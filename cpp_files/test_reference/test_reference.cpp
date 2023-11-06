#include <iostream>
using namespace std;

int multiply(const int &a, const int &b);
int multiplySimple(int a, int b);

int main() {

    int a = 5, b = 10;
    int res1 = multiply(a, b);
    int res2 = multiplySimple(a, b);
    cout << "Using Pass by Reference Result is " << res1 << endl;
    cout << "Using Pass by Value Result is " << res2 << endl;
    if (res1 == res2) 
        cout << "As you can see they are exactly the same lol!" << endl;

    return 0;
}

int multiply(int &a, int &b) {
    return a*b;
}

int multiplySimple(int a, int b) {
    return a*b;
}