#include "test.h"

class BridgeHand { 
    private:
        int *spades;
        int *hearts;
        int *diamonds;
        int *clubs;
        int distribution[4];
        int hcp;
    public:
        void setSpades(int *s, int num);
        void setHearts(int *h, int num);
        void setDiamonds(int *d, int num);
        void setClubs(int *c, int num);
        void printHand(void);
        int getTotalPoints(void);
        BridgeHand();
};

BridgeHand::BridgeHand() {
    hcp = 0;
    for (int i=0; i<4; i++) 
        distribution[i] = 0;
}
void BridgeHand::setSpades(int *s, int num) {
    for (int i=0; i<num; i++) {
        spades = new int[num];
        spades[i] = s[i];
        hcp += s[i];
    }    
    distribution[0] = num;
}
void BridgeHand::setHearts(int *s, int num) {
    for (int i=0; i<num; i++) {
        hearts = new int[num];
        hearts[i] = s[i];
        hcp += s[i];
    }
    distribution[1] = num;
}
void BridgeHand::setDiamonds(int *s, int num) {
    for (int i=0; i<num; i++) {
        diamonds = new int[num];
        diamonds[i] = s[i];
        hcp += s[i];
    }
    distribution[2] = num;
}
void BridgeHand::setClubs(int *s, int num) {
    for (int i=0; i<num; i++) {
        clubs = new int[num];
        clubs[i] = s[i];
        hcp += s[i];
    }
    distribution[3] = num;
}
void BridgeHand::printHand(void) {
    int numOfSpades = distribution[0];
    int numOfHearts = distribution[1];
    int numOfDiamonds = distribution[2];
    int numOfClubs = distribution[3];
    for (int i=0; i<numOfSpades; i++)
        cout << spades[i];
    cout << endl;
    for (int i=0; i<numOfHearts; i++)
        cout << hearts[i];
    cout << endl;
    for (int i=0; i<numOfDiamonds; i++)
        cout << diamonds[i];
    cout << endl;
    for (int i=0; i<numOfClubs; i++)
        cout << clubs[i];
    cout << endl;
}
int BridgeHand::getTotalPoints(void) {
    return hcp;
}


int main(void) {

    BridgeHand handNorth;
    int spadesN[] = {1,13,12,11,9,8};
    int heartsN[] = {1,13,9,8};
    int diamondsN[] = {1};
    int clubsN[] = {1,13};
    handNorth.setSpades(spadesN,6);
    handNorth.setHearts(heartsN,4);
    handNorth.setDiamonds(diamondsN,1);
    handNorth.setClubs(clubsN,2);

    handNorth.printHand();

    
    cout << "Testing to see if I can make Makefiles work in C++" << endl;
    cout << "Also testing to see how header files work" << endl;
    return 0;
}