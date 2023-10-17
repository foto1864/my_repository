#include <iostream>
#include <cstdlib>
using namespace std;

int argcv_sum(int* array, int size);
void swap(int* a, int* b);

int main(int argc, char *argv[]) {

    cout << "Argc is : " << argc << endl;

    int *p = (int*) malloc(argc * sizeof(int));

    for (int i = 1; i < argc; i++) {
        p[i] = atoi(argv[i]);
    }

    int sum = argcv_sum(p, argc-1);
    cout << "Sum of args in command line is : " << sum << endl;

    return 0;
}

int argcv_sum(int* array, int size) {
    int sum = 0;
    for (int i = 1; i <= size; i++) {
        sum += array[i];
    }
    return sum;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}