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

    // Δημιουργία του αρχείου
    code = BF_CreateFile(fileName);
    if (code != BF_OK) {
        BF_PrintError(code);
        return -1;
    }

    // Άνοιγμα του αρχείου και απόκτηση file descriptor
    int file_desc;
    code = BF_OpenFile(fileName, &file_desc);
    if (code != BF_OK) {
        BF_PrintError(code);
        return -1;
    }

    // Δέσμευση του πρώτου μπλοκ για τα μεταδεδομένα
    BF_Block *block;
    BF_Block_Init(&block);
    code = BF_AllocateBlock(file_desc, block);
    if (code != BF_OK) {
        BF_PrintError(code);
        BF_CloseFile(file_desc);
        BF_Block_Destroy(&block);
        return -1;
    }

    // Αρχικοποίηση μεταδεδομένων στο πρώτο block
    char *data = BF_Block_GetData(block);
    HP_info header_info;
    // Προσθήκη συγκεκριμένων αρχικών τιμών αν απαιτούνται
    memcpy(data, &header_info, sizeof(HP_info));

    // Σήμανση του block ως dirty και αποδέσμευση
    BF_Block_SetDirty(block);
    code = BF_UnpinBlock(block);
    if (code != BF_OK) {
        BF_PrintError(code);
        BF_CloseFile(file_desc);
        BF_Block_Destroy(&block);
        return -1;
    }

    BF_Block_Destroy(&block);

    // Κλείσιμο του αρχείου ανεξαρτήτως αποτελέσματος
    code = BF_CloseFile(file_desc);
    if (code != BF_OK) {
        BF_PrintError(code);
        return -1;
    }

    return 0; // Επιτυχής ολοκλήρωση
}

HP_info* HP_OpenFile(char *fileName, int *file_desc){
   BF_ErrorCode code;

    // Άνοιγμα του αρχείου
    code = BF_OpenFile(fileName, file_desc);
    if (code != BF_OK) {
        BF_PrintError(code);
        return NULL;
    }

    // Δέσμευση του πρώτου block για να διαβάσουμε τα μεταδεδομένα
    BF_Block *block;
    BF_Block_Init(&block);
    code = BF_GetBlock(*file_desc, 0, block);
    if (code != BF_OK) {
        BF_PrintError(code);
        BF_Block_Destroy(&block);
        return NULL;
    }

    // Ανάκτηση των μεταδεδομένων από το πρώτο block
    char *data = BF_Block_GetData(block);
    HP_info *header_info = malloc(sizeof(HP_info));
    if (header_info == NULL) {
        BF_UnpinBlock(block);
        BF_Block_Destroy(&block);
        return NULL;
    }
    memcpy(header_info, data, sizeof(HP_info));

    // Αποδέσμευση του block
    BF_UnpinBlock(block);
    BF_Block_Destroy(&block);

    return header_info; // Επιστροφή των μεταδεδομένων του αρχείου
}


int HP_CloseFile(int file_desc,HP_info* hp_info ){
}

int HP_InsertEntry(int file_desc,HP_info* hp_info, Record record){
    return -1;
}

int HP_GetAllEntries(int file_desc,HP_info* hp_info, int value){    
    return -1;
}

