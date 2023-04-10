#include <stdio.h>
#include <string.h>

typedef void* Pointer;

// Επιστρέφει τον μεγαλύτερο απο δύο ακεραίους

int compare_int(int a, int b) {
    if (a > b) {
        return a;
    }
    else return b;
}

// Επιστρέφει τον μεγαλύτερο από δύο floats

float compare_float(float a, float b) {
    if (a > b) {
        return a;
    }
    else return b;
}

// Επιστρέφει τον μεγαλύτερο απο δυο doubles

double compare_double(double a, double b) {
    if (a > b) {
        return a;
    }
    else return b;
}

typedef int (*function)(int a, int b);

int max(int a, int b, function f) {
    
}

int main() {

    int a = 5;
    int b = 7;

    int res = max(a, b, compare_int);

    if (res > 0) {
        printf("Biggest int is %d\n", a);
    }

}