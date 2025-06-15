#include <stdio.h>
#define SIZE 8

int main(void) {

    // Init Arrays
    int array_A[SIZE] = {2,6,6,7,7,10,9,9};
    int array_B[SIZE] = {3,6,7,8,8,9,9,10};

    //int f_x = 0;
    int sum_f_x = 0;

    int start_interval = -10;
    int end_interval = 10;

    // for (int x = start_interval; x < end_interval; x++) {
    //     for (int i = 0; i < SIZE; i++) {
    //         if (x > array_B[i]) {
    //             f_x = array_A[i] - x;
    //         }   
    //         else {
    //             f_x = 0;
    //         }
    //         //printf("f(%d) = %d\n", x, f_x);
    //         sum_f_x += f_x;
    //     }
    //     printf("F(%d) = %d\n", x,  sum_f_x);
    // }
    // return 0;

    int x = 2;
    
    int f_x[SIZE];
    for (int i=0; i<SIZE; i++) {
        f_x[i] = 0;
    }

    for (int i=0; i<SIZE; i++) {
        if (x > array_B[i]) {
            f_x[i] = array_A[i] - x;
        }
        else {
            f_x[i] = 0;
        }
    }

    for (int i=0; i<SIZE; i++) {
        sum_f_x += f_x[i];
    }

    printf("F(%d) = %d\n", x, sum_f_x);

}
