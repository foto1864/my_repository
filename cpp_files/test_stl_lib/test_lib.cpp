#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <random>
#include <limits>
#define STARTING_SIZE 10
using namespace std;

int get_random_int32(void);
void vector_print(const vector<int> &);
void list_print(const list<int> &);

int main(void) {

    // Vector Section
    vector<int> my_vector;
    vector<int>::iterator vector_iterator;

    for (int i=0; i<STARTING_SIZE; i++) {
        my_vector.push_back(get_random_int32() % 20);
    }
    cout << "Before sort is ran: " << endl;
    vector_print(my_vector);
    sort(my_vector.begin(), my_vector.end());
    cout << "After sort is ran: " << endl;
    vector_print(my_vector);

    // Using The Vector Iterator
    int i=0;
    for (vector_iterator=my_vector.begin(); vector_iterator<my_vector.end(); vector_iterator++) {
        cout << "Vector's value at: " << i++ << " is " << *vector_iterator << endl;
    }

    // List Section
    list<int> my_list;
    list<int>::iterator list_iterator;

    for (int i=0; i<STARTING_SIZE; i++) {
        my_list.push_back(get_random_int32() % 20);
    }

    cout << "Before sort is ran: " << endl;
    list_print(my_list);
    my_list.sort();
    cout << "After sort is ran: " << endl;
    list_print(my_list);

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

void vector_print(const vector<int> &vec) {
    for (int i=0; i<vec.size(); i++) {
        cout << "V[" << i << "] = " << vec[i] << endl;
    }
}

void list_print(const list<int> &my_list) {
   list<int>::const_iterator it;
   int i=0;
   for (it = my_list.begin(); it != my_list.end(); it++) {
       cout << "L[" << i++ << "] = " << *it << endl;
   }
}