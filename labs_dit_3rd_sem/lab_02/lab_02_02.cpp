#include <iostream>
using namespace std;
void swapForExA(int* a, int* b);
void swapForExB(int &a, int &b);
void swapForExC(int **a, int **b);

int main(void) {

    // Exercise 1
    cout << "Enter 2 numbers to be swapped:" << endl;
    int xA, yA;
    cin >> xA;
    cin >> yA;
    swapForExA(&xA, &yA);
    cout << "After swap the numbers are: " << xA << " " << yA << endl << endl;

    // Exercise 2
    cout << "Enter another 2 numbers to be swapped, using a different method:" << endl; 
    int xB, yB;
    cin >> xB;
    cin >> yB; 
    swapForExB(xB, yB);
    cout << "After swap the numbers are: " << xB << " " << yB << endl << endl;

    // Exercise 3
    cout << "Enter another 2 numbers to be swapped, using a different method:" << endl; 
    int xC, yC;
    cin >> xC;
    cin >> yC;
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
