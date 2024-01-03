#include <iostream>
#include <cstdlib>
using namespace std;

typedef enum {
    FIRST_SEM = 1,
    SECOND_SEM = 2,
    THIRD_SEM = 3,
    FOURTH_SEM = 4,
    FIFTH_SEM = 5,
    SIXTH_SEM = 6,
    SEVENTH_SEM = 7,
    EIGHTH_SEM = 8,
    NINTH_SEM = 9,
    TENTH_SEM = 10,
    ELEVENTH_SEM = 11,
    TWELVETH_SEM = 12,
} Semester;

int main(void) {
    Semester sem = FIRST_SEM;
    int semes = 5;
    cout << sizeof(semes) << endl;
    cout << sizeof(sem) << endl;
    cout << sem << endl;
    return 0;
}