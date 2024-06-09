#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// Συνάρτηση για να βρει το μέγιστο μήκος μιας παλινδρομικής υποσυμβολοσειράς και την αρχική της θέση
int longest_palindromic_substring(char* s, int* max_length, int* start_index) {
    int n = strlen(s);
    if (n == 0) {
        return -1;
    }

    // Δημιουργία και αρχικοποίηση του πίνακα dp
    bool dp[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = false;
        }
    }

    *max_length = 1;
    *start_index = 0;

    // Όλες οι συμβολοσειρές μήκους 1 είναι παλινδρομικές
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }

    // Έλεγχος για μεγαλύτερα μήκη
    for (int length = 2; length <= n; length++) {
        for (int i = 0; i < n - length + 1; i++) {
            int j = i + length - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                *start_index = i;
                *max_length = length;
            }
        }
    }
    return 0;
}

int main() {
    char s[] = "nisonanomimatamimonanosin";
    int max_length;
    int start_index;

    int returned = longest_palindromic_substring(s, &max_length, &start_index);
    if (returned < 0) {
        fprintf(stderr, "Fuck You.\n");
        exit(returned);
    }

    printf("Length of original string: %ld\n", strlen(s));
    printf("Max length of palindrome substring: %d\n", max_length);
    printf("Starting position of palindrome substring: %d\n", start_index+1);

    return 0;
}
