#include <stdio.h>
#include <stdlib.h>
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} info;

typedef info* Info;

int main(void) {

    int *array = malloc(5 * sizeof(int));
    for (int i=0; i<5; i++) {
        array[i] = 0;
    }

    Info *info_array = malloc(5 * sizeof(Info));
    for (int i=0; i<5; i++) {
        info_array[i] = NULL;
    }

    info_array[1]->age = 6;

    printf("The age of array[1] is %d", info_array[1]->age);

    return 0;
}