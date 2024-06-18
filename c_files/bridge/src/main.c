#include <stdio.h>
#include <stdlib.h>
#include "print_hand.h"

int main(void) {
    
    int dist[] = {4,4,4,4};

    Hand* hands[4];
    for (int i=0; i<4; i++) {
        hands[i] = malloc(sizeof(Hand));
    }
    for(int i=0; i<4; i++) {
        hands[i]->spades = (int*)malloc(4*sizeof(int));
        hands[i]->hearts = (int*)malloc(4*sizeof(int));
        hands[i]->diamonds = (int*)malloc(4*sizeof(int));
        hands[i]->clubs = (int*)malloc(4*sizeof(int));
    }
    for(int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            hands[i]->spades[j] = rand() % 8 + 2;
            hands[i]->hearts[j] = rand() % 8 + 2;
            hands[i]->diamonds[j] = rand() % 8 + 2;
            hands[i]->clubs[j] = rand() % 8 + 2;
        }
    }
    
    print_hand_north_or_south(hands[1], dist);
    print_hand_east_and_west(hands[0], hands[2], dist, dist);
    print_hand_north_or_south(hands[3], dist);

    return 0;
}