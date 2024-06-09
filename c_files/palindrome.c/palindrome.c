#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Συνάρτηση για να βρει το μέγιστο μήκος μιας παλινδρομικής υποσυμβολοσειράς και την αρχική της θέση
void longest_palindromic_substring(char* s, int* max_length, int* start_index) {
    int n = strlen(s);
    if (n == 0) {
        *max_length = 0;
        *start_index = -1;
        return;
    }

    bool dp[n][n];
    memset(dp, 0, sizeof(dp));

    *max_length = 1;
    *start_index = 0;

    // Όλες οι συμβολοσειρές μήκους 1 είναι παλινδρομικές
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }

    // Έλεγχος για συμβολοσειρές μήκους 2
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            *start_index = i;
            *max_length = 2;
        }
    }

    // Έλεγχος για μεγαλύτερα μήκη
    for (int length = 3; length <= n; length++) {
        for (int i = 0; i < n - length + 1; i++) {
            int j = i + length - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                *start_index = i;
                *max_length = length;
            }
        }
    }
}

int main() {
    char s[] = "nisonanomimatamimonanosin";
    int max_length;
    int start_index;

    longest_palindromic_substring(s, &max_length, &start_index);

    printf("Length of original string: %ld\n", strlen(s));
    printf("Max length of palindrome substring: %d\n", max_length);
    printf("Starting position of palindrome substring: %d\n", start_index+1);

    return 0;
}
