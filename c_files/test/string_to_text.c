#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int word_to_number(const char* word) {
    if (strcmp(word, "zero") == 0) return 0;
    if (strcmp(word, "one") == 0) return 1;
    if (strcmp(word, "two") == 0) return 2;
    if (strcmp(word, "three") == 0) return 3;
    if (strcmp(word, "four") == 0) return 4;
    if (strcmp(word, "five") == 0) return 5;
    if (strcmp(word, "six") == 0) return 6;
    if (strcmp(word, "seven") == 0) return 7;
    if (strcmp(word, "eight") == 0) return 8;
    if (strcmp(word, "nine") == 0) return 9;
    if (strcmp(word, "ten") == 0) return 10;
    if (strcmp(word, "eleven") == 0) return 11;
    if (strcmp(word, "twelve") == 0) return 12;
    if (strcmp(word, "thirteen") == 0) return 13;
    if (strcmp(word, "fourteen") == 0) return 14;
    if (strcmp(word, "fifteen") == 0) return 15;
    if (strcmp(word, "sixteen") == 0) return 16;
    if (strcmp(word, "seventeen") == 0) return 17;
    if (strcmp(word, "eighteen") == 0) return 18;
    if (strcmp(word, "nineteen") == 0) return 19;
    if (strcmp(word, "twenty") == 0) return 20;
    if (strcmp(word, "thirty") == 0) return 30;
    if (strcmp(word, "forty") == 0) return 40;
    if (strcmp(word, "fifty") == 0) return 50;
    if (strcmp(word, "sixty") == 0) return 60;
    if (strcmp(word, "seventy") == 0) return 70;
    if (strcmp(word, "eighty") == 0) return 80;
    if (strcmp(word, "ninety") == 0) return 90;
    return -1;
}

unsigned int parse_words_to_number(char* input) {
    char* token = strtok(input, " ");
    unsigned int number = 0, temp = 0;

    while (token != NULL) {
        if (strcmp(token, "thousand") == 0) {
            number += temp * 1000;
            temp = 0;
        } 
        else if (strcmp(token, "million") == 0) {
            temp*= 1000000;
        }
        else if (strcmp(token, "hundred") == 0) {
            temp *= 100;
        } 
        else {
            unsigned int val = word_to_number(token);
            if (val == -1) {
                printf("Unknown word: %s\n", token);
                return -1;
            }
            temp += val;
        }
        token = strtok(NULL, " ");
    }
    number += temp;
    return number;
}

int main() {
    char input[256];
    while(1) {
        printf("Enter a number in words (e.g., 'five thousand seventeen'): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;  // Remove newline

        unsigned int result = parse_words_to_number(input);
        if (result != -1) {
            printf("Numeric form: %u\n", result);
        }
    }
    return 0;
}
