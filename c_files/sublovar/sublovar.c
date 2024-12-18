// To do: We want a program that prints our name and age
#include <stdio.h>
#define BIRTH_YEAR 2004
#define CURRENT_YEAR 2024

typedef char* MIxalos;

int main() {

    MIxalos name = "El Michael";
    int age = CURRENT_YEAR - BIRTH_YEAR;

    printf("To onoma mou einai %s kai eimai %d xronon kai pleon spoudazo DI\n", name, age);
    return 0;
}