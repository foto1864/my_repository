#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(int);

int main(void) {

    vector<int> v;
    for (int i=0; i<10; i++) {
        v.push_back(0);
    }
    cout << "Size of vector is " << v.size() << endl;

    for (int i=0; i<5; i++) {
        v.pop_back();
    }

    cout << "After popping the chain the size of the vector is " << v.size() << endl;

    vector<int>::iterator Iter;
    for_each(v.begin(), v.end(), print);

    return 0;
}

void print(int n) {
    cout << n << endl;
}