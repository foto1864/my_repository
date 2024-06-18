#include "print_hand.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *spades;
    int *hearts;
    int *diamonds;
    int *clubs;
} Deck;

Deck *create_deck(void) {
    Deck *deck = malloc(sizeof(Deck));
    deck->spades = malloc(13*sizeof(int));
    deck->hearts = malloc(13*sizeof(int));
    deck->diamonds = malloc(13*sizeof(int));
    deck->clubs = malloc(13*sizeof(int));        
    for (int j=1; j<=13; j++) {
            deck->spades[j] = j; 
            deck->hearts[j] = j;
            deck->diamonds[j] = j;
            deck->clubs[j] = j;
    }
    return deck;
}

Hand* create_random_hand(Deck *deck) {
    Hand* hand = malloc(sizeof(Hand));
    int spades[13];
    int hearts[13];
    int diamonds[13];
    int clubs[13];
    int total_cards = 0;
    for (int i = 0; i<13; i++) {
        if ((rand()) % i == 0) 
            spades[i] = deck->spades[i];
            total_cards++;
    }
    for (int i = 0; i<13 - total_cards; i++) {
        if ((rand()) % i == 1) 
            hearts[i] = deck->hearts[i];
            total_cards++;
    }
    for (int i = 0; i<13 - total_cards; i++) {
        if ((rand()) % i == 2) 
            diamonds[i] = deck->diamonds[i];
            total_cards++;
    }
    for (int i = 0; i<13-total_cards; i++) {
        clubs[i] = deck->clubs[i];
        total_cards++;
    }
}