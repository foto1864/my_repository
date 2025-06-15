#include <stdio.h>
#include <stdlib.h>

#define MAX_SUM 1000  // Adjust this based on the expected maximum sum

int ***alloc3D(int n, int m, int s) {
    int ***matrix = malloc((n+1) * sizeof(int **));
    for (int i = 0; i <= n; i++) {
        matrix[i] = malloc((m+1) * sizeof(int *));
        for (int j = 0; j <= m; j++) {
            matrix[i][j] = calloc(s + 1, sizeof(int));
        }
    }
    return matrix;
}

void free3D(int ***matrix, int n, int m) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            free(matrix[i][j]);
        }
        free(matrix[i]);
    }
    free(matrix);
}

int count_paths_dp(int n, int m, int S, int** right, int** down) {
    int ***dp = alloc3D(n, m, S);
    dp[0][0][0] = 1;  // One way to have sum 0 at the start

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int s = 0; s <= S; s++) {
                if (i > 0 && s >= down[i-1][j])
                    dp[i][j][s] += dp[i-1][j][s - down[i-1][j]];
                if (j > 0 && s >= right[i][j-1])
                    dp[i][j][s] += dp[i][j-1][s - right[i][j-1]];
            }
        }
    }

    int result = dp[n][m][S];
    free3D(dp, n, m);
    return result;
}

int **alloc2D(int n, int m) {
    int **matrix = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        matrix[i] = malloc(m * sizeof(int));
    return matrix;
}

void free2D(int **matrix, int n) {
    for (int i = 0; i < n; i++)
        free(matrix[i]);
    free(matrix);
}

int main(void) {
    int n = 3, m = 4;
    int S = 15;  // Example target sum
    int** right = alloc2D(n+1, m);
    int** down =  alloc2D(n, m+1);

    // Random initialization of right and down matrices
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < m; j++)
            right[i][j] = rand() % 10;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m + 1; j++)
            down[i][j] = rand() % 10;

    int path_count = count_paths_dp(n, m, S, right, down);
    printf("Number of paths with sum %d: %d\n", S, path_count);

    free2D(right, n + 1);
    free2D(down, n);
    return 0;
}
