#include <stdio.h>
#include <stdlib.h>
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int date;           // Date 
    int month;          // Month
    int year;           // Year

} info;

typedef info* Info;

// USER INPUT
// DD/MM/YYYY NAME(str) \n

int main(void) {

    Info *info_array = malloc(2 * sizeof(Info));
    for (int i=0; i<2; i++) {
        info_array[i] = malloc(sizeof(*info_array));
    }

    int date[2];
    int month[2];
    int year[4];

    // Enter the birthday information of someone
    for (int i=0; i<2; i++) {
        date[0] = 10*(getchar()+48);
        date[1] = getchar()+48;
        info_array[i]->date = date[0] + date[1];
        getchar(); // Reads the expected "/"
        month[0] = 10*(getchar()+48);
        month[1] = getchar();
        info_array[i]->month = month[0] + month[1];
        getchar(); // Reads the expected "/"
        for(int j=0; j<4; j++) 
            year[j] = getchar()+48;
        info_array[i]->year = 1000*year[0]+100*year[1]+10*year[2]+year[3];
        fgets(info_array[i]->name, MAX_NAME_LENGTH, stdin);
    }

    for (int i=0; i<2; i++) {
        printf("Info of the peasant at info_array[%d] is:\n", i);
        printf("%d/%d/%d ", info_array[i]->date, info_array[i]->month, info_array[i]->year);
        printf(" His name is %s\n", info_array[i]->name);
    }

    return 0;
}