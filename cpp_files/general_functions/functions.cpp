#include "functions.hpp"

// Variables declared as static so that the function can return a different
// random value each time it gets called, changing a seed.
int get_random_int32(void){
    static random_device rd;
    static mt19937 gen(rd());
    static uniform_int_distribution<int> distribution(1, INT32_MAX);
    return distribution(gen);
}