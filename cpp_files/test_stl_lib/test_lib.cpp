#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <random>
#include <limits>
#define SIZE 10
using namespace std;


int get_random_int32(void);

int main(void) {

    // Vector Section
    vector<int> v;
    for (int i=0; i<SIZE; i++) {
        v.push_back(get_random_int32() % 2000);
    }
    cout << "Size of vector is " << v.size() << endl;
    vector<int>::iterator Iter;
    sort(v.begin(), v.end());
    for (int i=0; i<v.size(); i++) {
        cout << "V[" << i << "] = " << v[i] << endl;
    }


    // String Section
    string s1 = "Giannis";
    string s2 = "Foteinakis";
    string s3 = s1 + " " + s2;
    cout << "My name is " << s3 << endl;

    return 0;
}

int get_random_int32(void) {
    static random_device rd;
    static mt19937 gen(rd());
    static uniform_int_distribution<int> distribution(1, INT32_MAX);
    return distribution(gen);
}