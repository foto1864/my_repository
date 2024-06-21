#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int index;
    printf("Give number\n");
    scanf("%d", &index);

    // Allocate memory for the matrix (array of pointers)
    int **matrix = malloc(index * sizeof(int *));
    if (matrix == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Allocate memory for each row
    for (int i = 0; i < index; i++) {
        matrix[i] = malloc(index * sizeof(int));
        if (matrix[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }
    }

    // Initialize matrix to zero
    for (int i = 0; i < index; i++) {
        for (int j = 0; j < index; j++) {
            matrix[i][j] = 0;
        }
    }

    // Set the diagonal to 1
    for (int i = 0; i < index; i++) {
        matrix[i][i] = 1;
    }

    // Print the matrix
    for (int i = 0; i < index; i++) {
        for (int j = 0; j < index; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < index; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
