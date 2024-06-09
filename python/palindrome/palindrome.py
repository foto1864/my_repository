def longest_palindromic_substring(s):
    n = len(s)
    if n == 0:
        return 0, -1

    # Δημιουργία του πίνακα dp και αρχικοποίηση
    dp = [[False] * n for _ in range(n)]

    max_length = 1
    start_index = 0

    # Όλες οι συμβολοσειρές μήκους 1 είναι παλινδρομικές
    for i in range(n):
        dp[i][i] = True

    # Έλεγχος για συμβολοσειρές μήκους 2
    for i in range(n - 1):
        if s[i] == s[i + 1]:
            dp[i][i + 1] = True
            start_index = i
            max_length = 2

    # Έλεγχος για μεγαλύτερα μήκη
    for length in range(3, n + 1):  # length είναι το μήκος της υποσυμβολοσειράς
        for i in range(n - length + 1):
            j = i + length - 1  # Το τέλος της υποσυμβολοσειράς
            if s[i] == s[j] and dp[i + 1][j - 1]:
                dp[i][j] = True
                start_index = i
                max_length = length

    return max_length, start_index

# Παράδειγμα χρήσης
s = "nisonanomimatamimonanosin"
max_length, start_index = longest_palindromic_substring(s)
print("Length of starting string:", len(s))
print("Maximum length of palindrome substring:", max_length)
print("Starting position of palindrome substring:", start_index+1)
