#include <stdio.h>
#include <stdlib.h>
#include "print_hand.h"

int main(void) {
    
    Hand *first_hand = malloc(sizeof(Hand));

    first_hand->spades = malloc(4* sizeof(int));
    first_hand->hearts = malloc(4* sizeof(int));
    first_hand->diamonds = malloc(4* sizeof(int));
    first_hand->clubs = malloc(4* sizeof(int));

    for (int i=0; i<4; i++) {
        first_hand->clubs[i] = i;
        first_hand->diamonds[i] = i;
        first_hand->spades[i] = i;
        first_hand->hearts[i] = i;
    }

    int dist[] = {4,4,4,4};

    print_hand_north_or_south(first_hand, dist);
    print_hand_east_and_west(first_hand, first_hand, dist, dist);
    print_hand_north_or_south(first_hand, dist);

    return 0;
}