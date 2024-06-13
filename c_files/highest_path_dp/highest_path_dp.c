#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b) ((a) > (b) ? (a) : (b))

int **alloc2D(int n, int m) {
    int **matrix;
    matrix = malloc(n * sizeof(int *));
    for(int i = 0; i < n; i++) {
        matrix[i] = malloc(m * sizeof(int));
    }
    return matrix;
}

int highest_path_dp(int n, int m, int** right, int** down, int** grid) {
    int i, j;
    grid[0][0] = 0;
    for (j = 1; j <= m; j++)
        grid[0][j] = grid[0][j-1] + right[0][j-1];
    for (i = 1; i <= n; i++) {
        grid[i][0] = grid[i-1][0] + down[i-1][0];
        for (j = 1; j <= m; j++) {
            grid[i][j] = MAX(grid[i][j-1] + right[i][j-1], grid[i-1][j] + down[i-1][j]);
        }
    }
    return grid[n][m];
}

int main(void) {
    int n = 3, m = 4;
    int** right = alloc2D(n+1, m);
    int** down =  alloc2D(n, m+1);
    int** grid =  alloc2D(n+1, m+1);
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < m; j++)
            right[i][j] = rand() % 10;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m + 1; j++)
            down[i][j] = rand() % 10;
    int dist = highest_path_dp(n, m, right, down, grid);
    printf("Highest path has length %d\n", dist);
    for (int i = 0; i < n + 1; i++) {
        free(right[i]);
        free(grid[i]);
    }
    for (int i = 0; i < n; i++) {
        free(down[i]);
    }
    free(right);
    free(down);
    free(grid);
    return 0;
}
