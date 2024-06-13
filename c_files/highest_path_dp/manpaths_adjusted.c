#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100  // Μέγιστο μέγεθος του πίνακα
#define MAXS 1000 // Μέγιστο άθροισμα, προσαρμόστε ανάλογα

int countPaths(int m, int n, int A[MAXN][MAXN], int S) {
    int offset = S + MAXS; // Μετατοπίζουμε το άθροισμα για να είναι μη αρνητικό
    int **current = (int **)malloc((m + 1) * sizeof(int *));
    int **previous = (int **)malloc((m + 1) * sizeof(int *));
    for (int i = 0; i <= m; i++) {
        current[i] = (int *)malloc((2 * MAXS + 1) * sizeof(int));
        previous[i] = (int *)malloc((2 * MAXS + 1) * sizeof(int));
    }

    // Αρχικοποίηση των πινάκων
    for (int i = 0; i <= m; i++) {
        for (int k = 0; k <= 2 * MAXS; k++) {
            current[i][k] = 0;
            previous[i][k] = 0;
        }
    }

    // Αρχικοποίηση για τη θέση [1][1]
    previous[1][A[1][1] + offset] = 1;

    // Υπολογισμός του πίνακα δυναμικού προγραμματισμού
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= m; i++) {
            if (i == 1 && j == 1) continue; // Παραλείπουμε τη θέση αρχικοποίησης
            for (int s = -MAXS; s <= MAXS; s++) {
                int adjusted_sum = s + offset;
                if (adjusted_sum < 0 || adjusted_sum > 2 * MAXS) continue;
                current[i][adjusted_sum] = 0;
                if (i > 1 && adjusted_sum - A[i][j] >= 0 && adjusted_sum - A[i][j] <= 2 * MAXS) 
                    current[i][adjusted_sum] += previous[i-1][adjusted_sum - A[i][j]];
                if (j > 1 && adjusted_sum - A[i][j] >= 0 && adjusted_sum - A[i][j] <= 2 * MAXS) 
                    current[i][adjusted_sum] += previous[i][adjusted_sum - A[i][j]];
            }
        }
        // Αντιγραφή του current στον previous
        int **temp = previous;
        previous = current;
        current = temp;
    }

    // Αποθήκευση του αποτελέσματος
    int result = previous[m][S + offset];

    // Αποδέσμευση μνήμης
    for (int i = 0; i <= m; i++) {
        free(current[i]);
        free(previous[i]);
    }
    free(current);
    free(previous);

    return result;
}

int main() {
    int A[MAXN][MAXN] = {
        {0, 0, 0, 0},
        {0, 1, 2, 3},
        {0, 4, 5, 6},
        {0, 7, 8, 9}
    };
    int m = 3, n = 3;
    int S = 27;
    printf("Number of paths with sum %d: %d\n", S, countPaths(m, n, A, S));
    return 0;
}
