#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

typedef struct {
    int* spades;
    int* hearts;
    int* diamonds;
    int* clubs;
    int* dist;
} Hand;

bool print_hand(Hand* Hand, int* dist);
bool print_suit(int* array, int size, int suit);
char determine_suit(int suit);