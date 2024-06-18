#include "print_hand.h"

// will print the hand depending on where the player sits
bool print_hand(Hand* hand, int* dist) {
    print_suit(hand->spades, dist[0], 0);
    print_suit(hand->hearts, dist[1], 1);
    print_suit(hand->diamonds, dist[2], 2);
    print_suit(hand->clubs, dist[3], 3);
    return true;
}
// Takes an array of cards and the suit (S=0, H=1, D=2, C=3)
bool print_suit(int *array, int size, int suit) {
    
    char suit_char = determine_suit(suit);
    if (suit_char == 'F') 
        fprintf(stderr, "Wrong suit ID entered"); 

    if (size == 0) {
        printf("%c -\n", suit_char);
        return true;
    }
    printf("%c ", suit_char);

    for(int i=0; i<size; i++) {
        printf("%d", array[i]);
    }
    printf("\n");
    return true;
}

char determine_suit(int suit) {
    switch (suit) {
    case 0:
        return 'S';
    case 1:
        return 'H';
    case 2:
        return 'D';
    case 3:
        return 'C';
    default:
        return 'F';
        break;
    }
}