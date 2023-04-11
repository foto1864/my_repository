#include "minmax.h"

// Επιστρέφει τον μεγαλύτερο απο δύο ακεραίους
int compare_int(Pointer a, Pointer b) {
    int *pa = a;
    int *pb = b;
     if (*pa - *pb > 0) {
        return 1;
    }
    else return -1;
}

// Επιστρέφει τον μεγαλύτερο από δύο floats
int compare_float(Pointer a, Pointer b) {
    float *pa = a;
    float *pb = b;
     if (*pa - *pb > 0) {
        return 1;
    }
    else return -1;
}

// Επιστρέφει τον μεγαλύτερο απο δυο doubles
int compare_double(Pointer a, Pointer b) {
    double *pa = a;
    double *pb = b;
    if (*pa - *pb > 0) {
        return 1;
    }
    else return -1;
}