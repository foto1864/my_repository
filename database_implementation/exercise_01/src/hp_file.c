#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bf.h"
#include "hp_file.h"
#include "record.h"

#define CALL_BF(call)       \
{                           \
  BF_ErrorCode code = call; \
  if (code != BF_OK) {         \
    BF_PrintError(code);    \
    return HP_ERROR;        \
  }                         \
}

// Creates a file and returns it to the user.
int HP_CreateFile(char *fileName){
    BF_ErrorCode code;

    // Remove file if it already exists so that we dont get an error code by trying to create
    // a file with the same name as a that already exists. 
    if (remove(fileName) == 0) {
    } 

    // Create the file
    code = BF_CreateFile(fileName);
    if (code != BF_OK) {
        BF_PrintError(code);
        return -1;
    }

    // Open the file we just created and get the file descriptor, which is the code that 
    // represents the open(ed) file in our system. 
    int file_desc;
    code = BF_OpenFile(fileName, &file_desc);
    if (code != BF_OK) {
        BF_PrintError(code);
        return -1;
    }

    // The first block we allocate in the new file is for metadatea, meaning info about 
    // the structure and number of entries we are going to save in the file
    BF_Block *block;
    BF_Block_Init(&block);
    code = BF_AllocateBlock(file_desc, block);
    if (code != BF_OK) {
        BF_PrintError(code);
        BF_CloseFile(file_desc);
        BF_Block_Destroy(&block);
        return -1;
    }

    // In this step the function saves the metadata in the first block of the file
    char *data = BF_Block_GetData(block);
    HP_info header_info;
    // Set all bytes of the file to 0s. This is important in order to have a "clean"
    // structure and avoid unused fields and unused data.
    memset(&header_info, 0, sizeof(HP_info));   
    // Memcpy copies the content of the header info structre into the block. In this way
    // the block will contain its initial settings, e.g. at the start the number of entries is 0.
    memcpy(data, &header_info, sizeof(HP_info));

    // We mark the block as dirty, meaning that the changes have occured in the block, and then
    // we unpin it, meaning we release it back to the system.
    BF_Block_SetDirty(block); // tells the system that the block has been modified and needs to be saved again to memory
    code = BF_UnpinBlock(block); // tells the system that the block is ready to be released.
    if (code != BF_OK) {
        BF_PrintError(code);
        BF_CloseFile(file_desc);
        BF_Block_Destroy(&block);
        return -1;
    }

    // Finally we destroy the block, while freeing the memory it used in our
    BF_Block_Destroy(&block); // frees the memory used by the block, since its not needed anymore
    code = BF_CloseFile(file_desc); // closes the file while ensuring that every change has been saved.
    if (code != BF_OK) {
        BF_PrintError(code);
        return -1;
    }

    // File is ready to be used. In general what happened:
    // 1. The function deletes the file if it exists already, so that it can create a new one
    // 2. Creates and open said file
    // 3. Allocates a block for storing metadata and initializes it
    // 4. Returns the file back to storage.

    return 0;
}

// Opens the file for read and write
HP_info* HP_OpenFile(char *fileName, int *file_desc){
    BF_ErrorCode code;

    // Open the file with name "fileName" and get a discriptor for the system to use
    code = BF_OpenFile(fileName, file_desc);
    if (code != BF_OK) {
        BF_PrintError(code);
        return NULL; // return null if it fails
    }

    // The first block will contain the metadata of the file. We allocate a block, and in it
    // we store the block of the file that starts at index 0. This block contains the metadata of
    // the file, so now we have access to the file's metadata.
    BF_Block *block;
    BF_Block_Init(&block);
    code = BF_GetBlock(*file_desc, 0, block);
    if (code != BF_OK) {
        BF_PrintError(code);
        BF_Block_Destroy(&block);
        BF_CloseFile(*file_desc);
        return NULL;
    }

    // Now we start the process of copying the metadata of the file to the struct header info. 
    // The pointer "data" is a pointer to the bytes that contain the metadata of the file. We allocate
    // memory for the struct header info which will contain important info for processing the file. 
    // After the memory is allocated correctly we copy the data from data to header_info using memcpy.
    // This way, we can have the data in a struct that we can easily use in the code*.
    char *data = BF_Block_GetData(block);
    HP_info *header_info = malloc(sizeof(HP_info));
    if (header_info == NULL) {
        BF_UnpinBlock(block);
        BF_Block_Destroy(&block);
        BF_CloseFile(*file_desc);
        return NULL;
    }
    memcpy(header_info, data, sizeof(HP_info));

    // Unpin and destroy block (free)
    BF_UnpinBlock(block); // release the block
    BF_Block_Destroy(&block); // release the memory of block

    // Finally we return the header, which contains the metadata of the file just opened. In general what happened:
    // 1. We open the file and get the discriptor
    // 2. Get access to the first block containing the metadata
    // 3. Copy the data to header_info 
    // 4. Release block and return header_info.

    return header_info;
}

// Frees the memory allocated for metadata and closes the file
int HP_CloseFile(int file_desc,HP_info* hp_info ){
    // Free memory allocated for metadata, which we had dynamically allocated
    free(hp_info);

    // Closes the file and saves all potential changes. 
    BF_ErrorCode code = BF_CloseFile(file_desc);
    if (code != BF_OK) {
        BF_PrintError(code);
        return -1;
    }

    // Simply what happened:
    // 1. Freed allocated memory to avoid leaks
    // 2. Closed file making it ready to be used by other apps etc.
    // 3. Return 0 if everything is OK, and -1 otherwise.

    return 0;
}

// Inserts the entry "record" in a block of a heap file. If there is not enough
// space for the entry to be inserted it creates one. Finally it returns the 
// block number where the entry was placed.
int HP_InsertEntry(int file_desc, HP_info *header_info, Record record) {
    BF_ErrorCode code;
    BF_Block *block;
    BF_Block_Init(&block);

    // We find the last block that contains entries from the heap file, so now we know
    // where the MRU block is. 
    int block_num = header_info->last_block;  
    code = BF_GetBlock(file_desc, block_num, block);
    if (code != BF_OK) {
        BF_PrintError(code);
        BF_Block_Destroy(&block);
        return -1;
    }

    // Here we check if there is enough space for a nwe entry in the block. 
    char *data = BF_Block_GetData(block);
    int record_count;
    memcpy(&record_count, data, sizeof(int));

    // We have defined a MAX_RECORDS_PER_BLOCK constant in the hp_file.h file. If the records count
    // exceeds that number, that means that there is not enough space for the new entry to be placed
    // in the block, so we create a new block. We update record_count and block_num as we must.
    if (record_count >= MAX_RECORDS_PER_BLOCK) {  
        BF_UnpinBlock(block);
        BF_Block_Destroy(&block);

        BF_Block_Init(&block);
        code = BF_AllocateBlock(file_desc, block);
        if (code != BF_OK) {
            BF_PrintError(code);
            BF_Block_Destroy(&block);
            return -1;
        }
        block_num++;  // Increase the number of blocks for the new block 
        record_count = 0;  // Set entry count to 0 in the new block
        // we put the record number in the new block so that it is updated.
        memcpy(BF_Block_GetData(block), &record_count, sizeof(int));
    }

    // Finally we are ready to write the entry in the block. There will gave to be an offset that
    // is based on the number of records in the block + the int size for the record_count variable.
    data = BF_Block_GetData(block);
    int offset = sizeof(int) + record_count * sizeof(Record);  // sizeof(int) because record_count is int (obv)
    memcpy(data + offset, &record, sizeof(Record));

    // After the record is inserted, we update the record number in the block and mark it as dirty because 
    // it has been changed. We increase record count by 1 to signal the new entry and then we enter this new
    // number for record count at the start of the block. 
    record_count++;
    memcpy(data, &record_count, sizeof(int));
    BF_Block_SetDirty(block); // meaning that changes have been made and block needs to be saved again to disc

    // Unpin and destroy the block (free)
    code = BF_UnpinBlock(block); // means block is free for other apps and uses
    if (code != BF_OK) {
        BF_PrintError(code);
        BF_Block_Destroy(&block); // free the memory used by the block
        return -1;
    }

    // free the memory used by the block
    BF_Block_Destroy(&block);

    // Lastly we need to update the metadata to the header info
    header_info->record_count++; // increase total entries by 1
    header_info->last_block = block_num; // now the last block is the block where the insertion happened

    // Generally what happened: 
    // 1. Check if last block has available space
    // 2. If yes yes, if no then we create a new block
    // 3. Put new entry in the block
    // 4. Update metadata
    // 5. Return the block number where the insertion happened
    
    return block_num;  
}

// Searches for all entries that have the value "value" as their id, and returns
// the number of blocks that were read for the search.
int HP_GetAllEntries(int file_desc,HP_info* hp_info, int value){    
    BF_ErrorCode code;
    BF_Block *block;
    BF_Block_Init(&block);
    int blocks_read = 0;  // Counter for how many blocks have been read

    // Calculates how many blocks are in the file and saves it. We need to know how many
    // blocks there are so we can set an upper boundary for the for loop that follows.
    int total_blocks;
    code = BF_GetBlockCounter(file_desc, &total_blocks);
    if (code != BF_OK) {
        BF_PrintError(code);
        BF_Block_Destroy(&block);
        return -1;
    }

    // Here is the for loop, we go through each block in the file, and then for each
    // entry in the block, we simply check if the condition is met. In the process, we 
    // update the total number of blocks that have been read. 
    for (int i = 0; i < total_blocks; i++) {
        code = BF_GetBlock(file_desc, i, block);
        if (code != BF_OK) {
            BF_PrintError(code);
            BF_Block_Destroy(&block);
            return -1;
        }

        blocks_read++;  // Update the number of blocks we have read
        char *data = BF_Block_GetData(block); 

        int record_count;
        memcpy(&record_count, data, sizeof(int));

        // Search each entry in the block 
        for (int j = 0; j < record_count; j++) {
            Record record;
            int offset = sizeof(int) + j * sizeof(Record);
            memcpy(&record, data + offset, sizeof(Record));

            // Check if the id is the same as the one we want
            if (record.id == value) {
                // if we find it we print it
                printf("Record found - ID: %d, Name: %s, Surname: %s, City: %s\n",
                       record.id, record.name, record.surname, record.city);
            }
        }

        // Unpin destroy and move on to the next one etc.
        code = BF_UnpinBlock(block); // release it to the system
        if (code != BF_OK) {
            BF_PrintError(code);    
            BF_Block_Destroy(&block); // free it
            return -1;
        }
    }

    BF_Block_Destroy(&block);

    // In general what happened: 
    // 1. Calculate the number of total blocks
    // 2. Go through each block's entries searching for id equal to value
    // 3. Print the entries that match
    // 4. Return the number of blocks that were read

    return blocks_read;  
}

