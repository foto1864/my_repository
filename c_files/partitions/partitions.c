#include <stdio.h>
#include <stdbool.h>

bool canPartition(int* nums, int numsSize) {
    int total_sum = 0;
    for (int i = 0; i < numsSize; i++) {
        total_sum += nums[i];
    }

    // Αν το συνολικό άθροισμα είναι περιττό, δεν μπορούμε να το χωρίσουμε σε δύο ίσα μέρη
    if (total_sum % 2 != 0) {
        return false;
    }

    int target = total_sum / 2;

    // Δημιουργούμε πίνακα δυναμικού προγραμματισμού
    bool dp[target + 1];
    for (int i = 0; i <= target; i++) {
        dp[i] = false;
    }
    dp[0] = true;

    // Συμπλήρωση του πίνακα δυναμικού προγραμματισμού
    for (int i = 0; i < numsSize; i++) {
        for (int j = target; j >= nums[i]; j--) {
            dp[j] = dp[j] || dp[j - nums[i]];
        }
    }

    return dp[target];
}

int main() {
    int A[] = {1, 5, 12, 5};
    int size = sizeof(A) / sizeof(A[0]);

    if (canPartition(A, size)) {
        printf("Ναι, μπορούμε να χωρίσουμε το σύνολο σε δύο υποσύνολα με ίσο άθροισμα.\n");
    } else {
        printf("Όχι, δεν μπορούμε να χωρίσουμε το σύνολο σε δύο υποσύνολα με ίσο άθροισμα.\n");
    }

    return 0;
}
