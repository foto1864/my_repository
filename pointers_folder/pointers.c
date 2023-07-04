#include <stdio.h>

typedef void* Pointer;

int main() {
    char* string = "ABCD";
    Pointer a = string;
    printf("Pointer's value is: %s\n", (char*)a);
}