#include <iostream>
using namespace std;
void swapForExA(int* a, int* b);
void swapForExB(int &a, int &b);
void swapForExC(int **a, int **b);

int main(void) {
    int xA = 5, yA = 10;
    swapForExA(&xA, &yA);
    cout << "After swap the numbers are: " << xA << " " << yA << endl;

    int xB = 13, yB = 07; 
    swapForExB(xB, yB);
    cout << "After swap the numbers are: " << xB << " " << yB << endl;

    int xC = 20, yC = 12;
    int *ptr1 = &xC; 
    int *ptr2 = &yC;
    swapForExC(&ptr1, &ptr2);
    cout << "After swap the numbers are: " << *ptr1 << " " << *ptr2 << endl;

    return 0;
}

void swapForExA(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapForExB(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void swapForExC(int **a, int **b) {
    int *temp = *a;
    *a = *b;
    *b = temp;
}
