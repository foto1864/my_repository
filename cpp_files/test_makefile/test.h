#include <iostream>
using namespace std;

typedef enum Suit { Clubs = 1, Diamonds = 2, Hearts = 3, Spades = 4, NoTrump = 5};
//typedef enum Figure { Jack = 11, Queen = 12, King = 13, Ace = 1};

class Card {
    private:
        int value;
        Suit suit;
    public:
        void setValue(int v);
        void setSuit(Suit s);
        int getValue(void);
        int getSuit(void);
        Card();
        Card(int v, Suit s);
};

class BridgeHand {
    private:
        Card *hand;
        int totalPoints;
    public:
        void setHand(Card *array);
        void setTotalPoints(Card *array);
        int getTotalPoints(void);
        void printHand(void);
};