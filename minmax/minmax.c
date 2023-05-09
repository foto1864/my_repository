#include <stdio.h>
#include <stdlib.h>
#include "minmax.h"

// Η συνάρτηση επιστρέφει τον Pointer στον οποίο φυλάσσεται η
// μεγαλύτερη εκ των δύο τιμών a και b ανεξαρτήτως του τύπου τους
Pointer max(Pointer a, Pointer b, function f) {
    int result = f(a,b);
    if (result == 1) {
        return a;
    }
    else return b;
}

int main(void) {

    int intA = 5, intB = 7;
    float floatA = 6.44, floatB = 5.91;
    double doubleA = 7.9345, doubleB = 9.4612;
    String StringA = "Foto", StringB = "Espo";
    
    int *res1 = max(&intA, &intB, compare_int);
    float *res2 = max(&floatA, &floatB, compare_float);
    double *res3 = max(&doubleA, &doubleB, compare_double); 
    String res4 = max(StringA, StringB, (function) strcmp);
 
    printf("Max int between %d and %d is %d\n", intA, intB, *res1);
    printf("Max float between %4.2f and %4.2f is %4.2f\n", floatA, floatB, *res2);
    printf("Max double between %6.4f and %6.4f is %6.4f\n", doubleA, doubleB, *res3);
    printf("And Max String is %s\n", res4);

    return 0;
}