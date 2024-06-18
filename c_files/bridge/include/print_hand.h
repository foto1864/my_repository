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
bool print_hand_north_or_south(Hand* hand, int* dist);
bool print_hand_east_and_west(Hand* hand_east, Hand* hand_west, int* dist_east, int* dist_west);
bool print_suit(int* array, int size, int suit);
char determine_suit(int suit);