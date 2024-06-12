#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool can_be_split(int* array, int size) {
    int total_sum = 0;
    for (int i = 0; i < size; i++) {
        total_sum += array[i];
    }
    // if total sum is odd, then it can't be split in half (optimization)
    if (total_sum % 2 != 0) {
        return false;
    }
    int half_sum = total_sum / 2;
    // create dynamic programming array, set it to false
    bool dp[half_sum + 1];
    for (int i = 0; i < half_sum + 1; i++) {
        dp[i] = false;
    }
    dp[0] = true;
    // fill the array
    for (int i = 0; i < size; i++) {
        for (int j = half_sum; j >= array[i]; j--) {
            dp[j] = (dp[j] || dp[j - array[i]]);
        }
    }
    // return true if dp[half_sum] > 0.
    return dp[half_sum];
}

int main() {
    int* A;
    int get_size;
    printf("Give array size:\n");
    scanf("%d", &get_size);
    printf("Enter %d numbers that will go into the array:\n", get_size);
    A = malloc(get_size*sizeof(int));
    for(int i=0; i<get_size; i++) {
        scanf("%d", &A[i]);
    }
    if (can_be_split(A, get_size)) {
        printf("Set can be split.\n");
    } else {
        printf("Set can't be split.\n");
    }
    free(A);
    return 0;
}
