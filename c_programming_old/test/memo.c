#include <stdio.h>
#include <stdlib.h>

#define MAX 100 

unsigned int count = 0;
long long int memo[MAX]; 

void initializeMemoization() {
    for (int i = 0; i < MAX; i++) {
        memo[i] = -1; 
    }
}

long long int fibonacci(int n) {
    count++;
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }

    if (memo[n] != -1) {
        return memo[n];
    }

    memo[n] = fibonacci(n-1) + fibonacci(n-2);
    return memo[n];
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <n>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n < 0 || n >= MAX) {
        printf("Error: n should be in range 0 to %d\n", MAX-1);
        return 1;
    }

    initializeMemoization(); 
    printf("Fib(%d) is %lld\n", n, fibonacci(n));
    printf("Function was called %d times.\n", count);

    return 0;
}
