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

    //printf("Starting HP_CreateFile for file: %s\n", fileName);

    // Remove file if it already exists
    if (remove(fileName) == 0) {
        //printf("Existing file %s deleted successfully\n", fileName);
    } else {
        //printf("File %s does not exist or cannot be deleted\n", fileName);
    }

    // Create the actual file
    code = BF_CreateFile(fileName);
    if (code != BF_OK) {
        BF_PrintError(code);
        //printf("Error in BF_CreateFile\n");
        return -1;
    }

    // Open the file and get the file descriptor
    int file_desc;
    code = BF_OpenFile(fileName, &file_desc);
    if (code != BF_OK) {
        BF_PrintError(code);
        //printf("Error in BF_OpenFile\n");
        return -1;
    }
    //printf("File opened successfully with file_desc: %d\n", file_desc);

    // Allocate the first block for metadatea
    BF_Block *block;
    BF_Block_Init(&block);
    code = BF_AllocateBlock(file_desc, block);
    if (code != BF_OK) {
        BF_PrintError(code);
        //printf("Error in BF_AllocateBlock\n");
        BF_CloseFile(file_desc);
        BF_Block_Destroy(&block);
        return -1;
    }
    //printf("Block allocated successfully\n");

    // Initialize metadata in the first block
    char *data = BF_Block_GetData(block);
    HP_info header_info;
    memset(&header_info, 0, sizeof(HP_info));   // Initialize to 0s to avoid unused fields
    memcpy(data, &header_info, sizeof(HP_info));
    //printf("Metadata initialized\n");

    // Mark the block as dirty and unpin it
    BF_Block_SetDirty(block);
    code = BF_UnpinBlock(block);
    if (code != BF_OK) {
        BF_PrintError(code);
        //printf("Error in BF_UnpinBlock\n");
        BF_CloseFile(file_desc);
        BF_Block_Destroy(&block);
        return -1;
    }

    // Destroy the block and close the file
    BF_Block_Destroy(&block);
    code = BF_CloseFile(file_desc);
    if (code != BF_OK) {
        BF_PrintError(code);
        //printf("Error in BF_CloseFile\n");
        return -1;
    }
    // printf("File closed successfully in HP_CreateFile\n");

    return 0;
}

HP_info* HP_OpenFile(char *fileName, int *file_desc){
    BF_ErrorCode code;

    // printf("Starting HP_OpenFile for file: %s\n", fileName);

    // Open the file
    code = BF_OpenFile(fileName, file_desc);
    if (code != BF_OK) {
        BF_PrintError(code);
        // printf("Error in BF_OpenFile\n");
        return NULL;
    }
    // printf("File opened successfully in HP_OpenFile with file_desc: %d\n", *file_desc);

    // Allocate first block for metadata
    BF_Block *block;
    BF_Block_Init(&block);
    code = BF_GetBlock(*file_desc, 0, block);
    if (code != BF_OK) {
        BF_PrintError(code);
        // printf("Error in BF_GetBlock\n");
        BF_Block_Destroy(&block);
        BF_CloseFile(*file_desc);
        return NULL;
    }
    // printf("Block retrieved successfully\n");

    // Get metadata info and copy to the HP_info struct
    char *data = BF_Block_GetData(block);
    HP_info *header_info = malloc(sizeof(HP_info));
    if (header_info == NULL) {
        BF_UnpinBlock(block);
        BF_Block_Destroy(&block);
        BF_CloseFile(*file_desc);
        //printf("Error allocating memory for header_info\n");
        return NULL;
    }
    memcpy(header_info, data, sizeof(HP_info));
    //printf("Metadata loaded into header_info\n");

    // Unpin and destroy block (free)
    BF_UnpinBlock(block);
    BF_Block_Destroy(&block);

    return header_info;
}


int HP_CloseFile(int file_desc,HP_info* hp_info ){
    // printf("Starting HP_CloseFile for file_desc: %d\n", file_desc);

    // Free memory allocated for metadata
    free(hp_info);
    // printf("header_info memory freed\n");

    // Close the file
    BF_ErrorCode code = BF_CloseFile(file_desc);
    if (code != BF_OK) {
        BF_PrintError(code);
        // printf("Error in BF_CloseFile\n");
        return -1;
    }

    // printf("File closed successfully in HP_CloseFile\n");
    return 0;
}

int HP_InsertEntry(int file_desc, HP_info *header_info, Record record) {
    BF_ErrorCode code;
    BF_Block *block;
    BF_Block_Init(&block);

    int block_num = header_info->lastBlock;  // Το τελευταίο block με εγγραφές
    code = BF_GetBlock(file_desc, block_num, block);
    if (code != BF_OK) {
        BF_PrintError(code);
        BF_Block_Destroy(&block);
        return -1;
    }

    // Έλεγχος αν υπάρχει χώρος για νέα εγγραφή στο block
    char *data = BF_Block_GetData(block);
    int record_count;
    memcpy(&record_count, data, sizeof(int));

    if (record_count >= MAX_RECORDS_PER_BLOCK) {  // Αν δεν υπάρχει χώρος, δημιουργούμε νέο block
        BF_UnpinBlock(block);
        BF_Block_Destroy(&block);

        BF_Block_Init(&block);
        code = BF_AllocateBlock(file_desc, block);
        if (code != BF_OK) {
            BF_PrintError(code);
            BF_Block_Destroy(&block);
            return -1;
        }
        block_num++;  // Αυξάνουμε τον αριθμό του block για το νέο block
        record_count = 0;  // Μηδενίζουμε τον αριθμό εγγραφών στο νέο block
        memcpy(BF_Block_GetData(block), &record_count, sizeof(int));
    }

    // Εισαγωγή της εγγραφής στο block
    data = BF_Block_GetData(block);
    int offset = sizeof(int) + record_count * sizeof(Record);  // sizeof(int) για τον αριθμό εγγραφών
    memcpy(data + offset, &record, sizeof(Record));

    // Ενημέρωση του αριθμού των εγγραφών στο block και σηματοδότηση dirty
    record_count++;
    memcpy(data, &record_count, sizeof(int));
    BF_Block_SetDirty(block);

    // Unpin και αποδέσμευση του block
    code = BF_UnpinBlock(block);
    if (code != BF_OK) {
        BF_PrintError(code);
        BF_Block_Destroy(&block);
        return -1;
    }

    BF_Block_Destroy(&block);

    // Ενημέρωση των μεταδεδομένων στο header_info
    header_info->recordCount++;
    header_info->lastBlock = block_num;

    return block_num;  // Επιστρέφουμε τον αριθμό του block όπου έγινε η εισαγωγή
}

int HP_GetAllEntries(int file_desc,HP_info* hp_info, int value){    
    BF_ErrorCode code;
    BF_Block *block;
    BF_Block_Init(&block);
    int blocks_read = 0;  // Μετρητής για τα blocks που διαβάστηκαν

    int total_blocks;
    code = BF_GetBlockCounter(file_desc, &total_blocks);
    if (code != BF_OK) {
        BF_PrintError(code);
        BF_Block_Destroy(&block);
        return -1;
    }

    // Διατρέχουμε κάθε block στο αρχείο
    for (int i = 0; i < total_blocks; i++) {
        code = BF_GetBlock(file_desc, i, block);
        if (code != BF_OK) {
            BF_PrintError(code);
            BF_Block_Destroy(&block);
            return -1;
        }

        blocks_read++;  // Αυξάνουμε τον αριθμό των blocks που διαβάσαμε
        char *data = BF_Block_GetData(block);

        int record_count;
        memcpy(&record_count, data, sizeof(int));

        // Αναζητούμε κάθε εγγραφή στο block
        for (int j = 0; j < record_count; j++) {
            Record record;
            int offset = sizeof(int) + j * sizeof(Record);
            memcpy(&record, data + offset, sizeof(Record));

            // Έλεγχος αν το πεδίο-κλειδί id είναι ίσο με το ζητούμενο
            if (record.id == value) {
                printf("Record found - ID: %d, Name: %s, Surname: %s, City: %s\n",
                       record.id, record.name, record.surname, record.city);
            }
        }

        // Unpin το block πριν προχωρήσουμε στο επόμενο
        code = BF_UnpinBlock(block);
        if (code != BF_OK) {
            BF_PrintError(code);
            BF_Block_Destroy(&block);
            return -1;
        }
    }

    BF_Block_Destroy(&block);
    return blocks_read;  // Επιστρέφουμε τον αριθμό των blocks που διαβάστηκαν
}

