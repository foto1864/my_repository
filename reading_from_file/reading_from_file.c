#include <stdio.h>
#include <stdlib.h>
#define SIZE 1500

int main() {
    fprintf(stdout, "Reading From File Demo\n");

    FILE * demo = fopen("demo.txt", "r");

    char array[SIZE];

    while (!feof(demo)) {
        fgets(array, SIZE, demo);
        puts(array);
    }

    fclose(demo);

    return 0;
}