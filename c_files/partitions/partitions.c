#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool can_be_split(int* nums, int numsSize) {
    int total_sum = 0;
    for (int i = 0; i < numsSize; i++) {
        total_sum += nums[i];
    }
    // if total sum is odd, then it can't be split in half (optimization)
    if (total_sum % 2 != 0) {
        return false;
    }
    int target = total_sum / 2;
    // create dynamic programming array
    bool dp[target + 1];
    for (int i = 0; i <= target; i++) {
        dp[i] = false;
    }
    dp[0] = true;
    // fill the array
    for (int i = 0; i < numsSize; i++) {
        for (int j = target; j >= nums[i]; j--) {
            dp[j] = dp[j] || dp[j - nums[i]];
        }
    }
    // return true if dp[target] > 0.
    return dp[target];
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
