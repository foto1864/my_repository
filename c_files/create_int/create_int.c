#include <stdio.h>
#include <stdlib.h>

int* create_int(int value) {
    int* new_int = malloc(sizeof(int));
    *new_int = value;
    return new_int;
}

int main(void) {
    
    int* p = create_int(12312);
    printf("%d\n", *p);
    
    return 0;
}