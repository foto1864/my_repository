#include <stdio.h>
#include <stdlib.h>
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int date;           // Date 
    int month;          // Month
    int year;           // Year
    int hours;          // Hours
    int minutes;        // Minutes
} info;

typedef info* Info;

// USER INPUT
// DD/MM/YYYY NAME(str) \n

int main(void) {

    int *array = malloc(5 * sizeof(int));
    for (int i=0; i<5; i++) {
        array[i] = 0;
    }

    Info *info_array = malloc(5 * sizeof(Info));
    for (int i=0; i<5; i++) {
        info_array[i] = malloc(sizeof(*info_array));
    }

    // ascii 49 is dec 01
    int date[2];
    date[0] = 10*(getchar() + 48);
    date[1] = getchar + 48;

    return 0;
}