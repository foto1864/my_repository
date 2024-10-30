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

    printf("Starting HP_CreateFile for file: %s\n", fileName);

    // Διαγραφή του αρχείου αν υπάρχει ήδη
    if (remove(fileName) == 0) {
        printf("Existing file %s deleted successfully\n", fileName);
    } else {
        printf("File %s does not exist or cannot be deleted\n", fileName);
    }

    // Δημιουργία του αρχείου
    code = BF_CreateFile(fileName);
    if (code != BF_OK) {
        BF_PrintError(code);
        printf("Error in BF_CreateFile\n");
        return -1;
    }

    // Άνοιγμα του αρχείου και απόκτηση του file descriptor
    int file_desc;
    code = BF_OpenFile(fileName, &file_desc);
    if (code != BF_OK) {
        BF_PrintError(code);
        printf("Error in BF_OpenFile\n");
        return -1;
    }
    printf("File opened successfully with file_desc: %d\n", file_desc);

    // Δέσμευση του πρώτου block για τα μεταδεδομένα
    BF_Block *block;
    BF_Block_Init(&block);
    code = BF_AllocateBlock(file_desc, block);
    if (code != BF_OK) {
        BF_PrintError(code);
        printf("Error in BF_AllocateBlock\n");
        BF_CloseFile(file_desc);
        BF_Block_Destroy(&block);
        return -1;
    }
    printf("Block allocated successfully\n");

    // Αρχικοποίηση μεταδεδομένων στο πρώτο block
    char *data = BF_Block_GetData(block);
    HP_info header_info;
    memset(&header_info, 0, sizeof(HP_info)); // Αρχικοποίηση δομής σε μηδενικά για αποφυγή αχρησιμοποίητων πεδίων
    memcpy(data, &header_info, sizeof(HP_info));
    printf("Metadata initialized\n");

    // Σήμανση του block ως dirty και αποδέσμευση
    BF_Block_SetDirty(block);
    code = BF_UnpinBlock(block);
    if (code != BF_OK) {
        BF_PrintError(code);
        printf("Error in BF_UnpinBlock\n");
        BF_CloseFile(file_desc);
        BF_Block_Destroy(&block);
        return -1;
    }

    // Καταστροφή του block και κλείσιμο του αρχείου
    BF_Block_Destroy(&block);
    code = BF_CloseFile(file_desc);
    if (code != BF_OK) {
        BF_PrintError(code);
        printf("Error in BF_CloseFile\n");
        return -1;
    }
    printf("File closed successfully in HP_CreateFile\n");

    return 0;
}

HP_info* HP_OpenFile(char *fileName, int *file_desc){
    BF_ErrorCode code;

    printf("Starting HP_OpenFile for file: %s\n", fileName);

    // Άνοιγμα του αρχείου
    code = BF_OpenFile(fileName, file_desc);
    if (code != BF_OK) {
        BF_PrintError(code);
        printf("Error in BF_OpenFile\n");
        return NULL;
    }
    printf("File opened successfully in HP_OpenFile with file_desc: %d\n", *file_desc);

    // Δέσμευση του πρώτου block για ανάκτηση μεταδεδομένων
    BF_Block *block;
    BF_Block_Init(&block);
    code = BF_GetBlock(*file_desc, 0, block);
    if (code != BF_OK) {
        BF_PrintError(code);
        printf("Error in BF_GetBlock\n");
        BF_Block_Destroy(&block);
        BF_CloseFile(*file_desc);
        return NULL;
    }
    printf("Block retrieved successfully\n");

    // Ανάκτηση μεταδεδομένων και αντιγραφή στη δομή HP_info
    char *data = BF_Block_GetData(block);
    HP_info *header_info = malloc(sizeof(HP_info));
    if (header_info == NULL) {
        BF_UnpinBlock(block);
        BF_Block_Destroy(&block);
        BF_CloseFile(*file_desc);
        printf("Error allocating memory for header_info\n");
        return NULL;
    }
    memcpy(header_info, data, sizeof(HP_info));
    printf("Metadata loaded into header_info\n");

    // Αποδέσμευση του block
    BF_UnpinBlock(block);
    BF_Block_Destroy(&block);

    return header_info;
}


int HP_CloseFile(int file_desc,HP_info* hp_info ){
    printf("Starting HP_CloseFile for file_desc: %d\n", file_desc);

    // Αποδέσμευση της δυναμικής μνήμης για τα μεταδεδομένα
    free(hp_info);
    printf("header_info memory freed\n");

    // Κλείσιμο του αρχείου
    BF_ErrorCode code = BF_CloseFile(file_desc);
    if (code != BF_OK) {
        BF_PrintError(code);
        printf("Error in BF_CloseFile\n");
        return -1;
    }

    printf("File closed successfully in HP_CloseFile\n");
    return 0;
}

int HP_InsertEntry(int file_desc,HP_info* hp_info, Record record){
    return -1;
}

int HP_GetAllEntries(int file_desc,HP_info* hp_info, int value){    
    return -1;
}

