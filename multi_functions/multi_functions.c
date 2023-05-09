#include <stdio.h>
#include <stdlib.h>

int twice(int value) {
    return 2 * value;
}

int increment(int value) {
    return value + 1;
}

int square(int value) {
    return value * value;
}

typedef int (*function)(int value);

int call_function(int value, function f) {
    return f(value);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Wrong usage!\n");
        exit(1);
    }
    
    int a = atoi(argv[1]);
    int res1 = call_function(a, twice);
    int res2 = call_function(a, increment);
    int res3 = call_function(a, square);

    printf("After 'twice' ran on %d the result is %d\n", a, res1);
    printf("After 'increment' ran on %d the result is %d\n", a, res2);
    printf("After 'square' ran on %d the result is %d\n", a, res3);

    return 0;    
}