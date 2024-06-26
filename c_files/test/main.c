#include <stdio.h>
#include <stdlib.h>

unsigned int count = 0;

int fibonacci(int n) {    
    count++;
    if (n==0) { 
        return 0;
    }
    else if (n==1) {
        return 1;
    } 
    return fibonacci(n-2)+fibonacci(n-1);
}

int main(int argc, char **argv) {
    int n = atoi(argv[1]);
    printf("Fib(%d) is %d\n", n, fibonacci(n));
    printf("Function was called %d times.\n", count);
    return 0;
}