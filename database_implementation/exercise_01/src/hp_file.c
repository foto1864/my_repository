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

int HP_CreateFile(char *fileName){
    BF_ErrorCode code;

    // Remove file if it already exists so that we dont get an error code
    if (remove(fileName) == 0) {
    } 

    // Create the actual file
    code = BF_CreateFile(fileName);
    if (code != BF_OK) {
        BF_PrintError(code);
        return -1;
    }

    // Open the file and get the file descriptor
    int file_desc;
    code = BF_OpenFile(fileName, &file_desc);
    if (code != BF_OK) {
        BF_PrintError(code);
        return -1;
    }

    // Allocate the first block for metadatea
    BF_Block *block;
    BF_Block_Init(&block);
    code = BF_AllocateBlock(file_desc, block);
    if (code != BF_OK) {
        BF_PrintError(code);
        BF_CloseFile(file_desc);
        BF_Block_Destroy(&block);
        return -1;
    }

    // Initialize metadata in the first block
    char *data = BF_Block_GetData(block);
    HP_info header_info;
    memset(&header_info, 0, sizeof(HP_info));   // Initialize to 0s to avoid unused fields
    memcpy(data, &header_info, sizeof(HP_info));

    // Mark the block as dirty and unpin it
    BF_Block_SetDirty(block);
    code = BF_UnpinBlock(block);
    if (code != BF_OK) {
        BF_PrintError(code);
        BF_CloseFile(file_desc);
        BF_Block_Destroy(&block);
        return -1;
    }

    // Destroy the block and close the file
    BF_Block_Destroy(&block);
    code = BF_CloseFile(file_desc);
    if (code != BF_OK) {
        BF_PrintError(code);
        return -1;
    }

    return 0;
}

HP_info* HP_OpenFile(char *fileName, int *file_desc){
    BF_ErrorCode code;

    // Open the file
    code = BF_OpenFile(fileName, file_desc);
    if (code != BF_OK) {
        BF_PrintError(code);
        return NULL;
    }

    // Allocate first block for metadata
    BF_Block *block;
    BF_Block_Init(&block);
    code = BF_GetBlock(*file_desc, 0, block);
    if (code != BF_OK) {
        BF_PrintError(code);
        BF_Block_Destroy(&block);
        BF_CloseFile(*file_desc);
        return NULL;
    }

    // Get metadata info and copy to the HP_info struct
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
    BF_UnpinBlock(block);
    BF_Block_Destroy(&block);

    return header_info;
}


int HP_CloseFile(int file_desc,HP_info* hp_info ){
    // Free memory allocated for metadata
    free(hp_info);

    // Close the file
    BF_ErrorCode code = BF_CloseFile(file_desc);
    if (code != BF_OK) {
        BF_PrintError(code);
        return -1;
    }
    return 0;
}

int HP_InsertEntry(int file_desc, HP_info *header_info, Record record) {
    BF_ErrorCode code;
    BF_Block *block;
    BF_Block_Init(&block);

    int block_num = header_info->last_block;  // Τhe last block with entries
    code = BF_GetBlock(file_desc, block_num, block);
    if (code != BF_OK) {
        BF_PrintError(code);
        BF_Block_Destroy(&block);
        return -1;
    }

    // Check if there is space for a nwe entry in the block
    char *data = BF_Block_GetData(block);
    int record_count;
    memcpy(&record_count, data, sizeof(int));

    if (record_count >= MAX_RECORDS_PER_BLOCK) {  // If there is no space we create a new block
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
        memcpy(BF_Block_GetData(block), &record_count, sizeof(int));
    }

    // Put a new entry in the block
    data = BF_Block_GetData(block);
    int offset = sizeof(int) + record_count * sizeof(Record);  // sizeof(int) because record_count is int (obv)
    memcpy(data + offset, &record, sizeof(Record));

    // Update record number in the block and mark as dirty
    record_count++;
    memcpy(data, &record_count, sizeof(int));
    BF_Block_SetDirty(block);

    // Unpin and destroy the block (free)
    code = BF_UnpinBlock(block);
    if (code != BF_OK) {
        BF_PrintError(code);
        BF_Block_Destroy(&block);
        return -1;
    }

    BF_Block_Destroy(&block);

    // Update the metadata for header_info
    header_info->record_count++;
    header_info->last_block = block_num;

    return block_num;  // Return the block number where the insertion happened
}

int HP_GetAllEntries(int file_desc,HP_info* hp_info, int value){    
    BF_ErrorCode code;
    BF_Block *block;
    BF_Block_Init(&block);
    int blocks_read = 0;  // Counter for how many blocks have been read

    int total_blocks;
    code = BF_GetBlockCounter(file_desc, &total_blocks);
    if (code != BF_OK) {
        BF_PrintError(code);
        BF_Block_Destroy(&block);
        return -1;
    }

    // We go through each block in the file
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
                printf("Record found - ID: %d, Name: %s, Surname: %s, City: %s\n",
                       record.id, record.name, record.surname, record.city);
            }
        }

        // Unpin destroy and move on to the next one
        code = BF_UnpinBlock(block);
        if (code != BF_OK) {
            BF_PrintError(code);
            BF_Block_Destroy(&block);
            return -1;
        }
    }

    BF_Block_Destroy(&block);
    return blocks_read;  // Return the number of blocks that were read
}

