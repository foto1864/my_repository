#include <iostream>
#include "test.h"
using namespace std;

///////////////////////////// Functions of Class Card ///////////////////////////////

void Card::setValue(int v) {
    value = v;
}
void Card::setSuit(Suit s) {
    suit = s;
}
int Card::getSuit(void) {
    return suit;
}
int Card::getValue(void) {
    return value;
}
Card::Card(): value(0), suit(NoTrump) {}
Card::Card(int v, Suit s): value(v), suit(s) {}

////////////////////////// Functions of Class BridgeHand //////////////////////////// 

void BridgeHand::setHand(Card *array) {
    hand = new Card[13];
    for (int i=0; i<13; i++) {
        hand[i] = array[i];
    }
}
void BridgeHand::setTotalPoints(Card *array) {
    int hcp = 0; 
    for (int i=0; i<13; i++) {
        hcp += array[i].getValue();
    }
    totalPoints = hcp;
}
int BridgeHand::getTotalPoints(void) {
    return totalPoints;
}
void BridgeHand::printHand(void) {
    for (int i=0; i<13; i++) {
        cout << hand[i].getValue() << " ";
    }
    cout << endl;
}

int main(void) {
    
    Card c1(1, 1);
    Card c2(13, 1);
    Card c3

    cout << "Testing to see if I can make Makefiles work in C++" << endl;
    cout << "Also testing to see how header files work" << endl;
    return 0;
}