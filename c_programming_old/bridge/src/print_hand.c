#include "print_hand.h"

// will print the hand depending on where the player sits
bool print_hand_north_or_south(Hand* hand, int* dist) {
    printf("\n                "); print_suit(hand->spades, dist[0], 0);
    printf("\n                "); print_suit(hand->hearts, dist[1], 1);
    printf("\n                "); print_suit(hand->diamonds, dist[2], 2);
    printf("\n                "); print_suit(hand->clubs, dist[3], 3);
    putchar(10);
    return true;
}

bool print_hand_east_and_west(Hand* hand_east, Hand* hand_west, int* dist_east, int* dist_west) {
    print_suit(hand_east->spades, dist_east[0], 0);   printf("                           ");  print_suit(hand_west->spades, dist_west[0], 0);
    putchar(10);
    print_suit(hand_east->hearts, dist_east[1], 1);   printf("                           ");  print_suit(hand_west->hearts, dist_west[1], 1);
    putchar(10);
    print_suit(hand_east->diamonds, dist_east[2], 2); printf("                           ");  print_suit(hand_west->diamonds, dist_west[2], 2);
    putchar(10);
    print_suit(hand_east->clubs, dist_east[3], 3);    printf("                           ");  print_suit(hand_west->clubs, dist_west[3], 3);
    putchar(10);
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