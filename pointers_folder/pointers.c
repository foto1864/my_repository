#include <stdio.h>

typedef int espo;

void swap(int *a, int *b) {
    int temp = *a; // temp = 5
    *a = *b; // a = 10
    *b = temp; // b = 5 

}

int main() {
    espo d = 7;
    int a = 5;
    int *pa = &a;
    int b = 10;
    int *pb = &b;
    swap(pa, &d);
    printf("%d , %d\n", a, d);
    return 0;
}