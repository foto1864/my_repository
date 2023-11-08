#include <iostream>
using namespace std;

typedef enum Suit { 1 = Clubs; 2 = Diamonds; 3 = Hearts; 4 = Spades};
typedef enum Figure { 11 = Jack; 12 = Queen; 13 = King};

class Card {
    private:
        int value;
        Suit suit;

};

class BridgeHand {

};