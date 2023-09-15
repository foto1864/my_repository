#include "acutest.h"
#include "test_acutest.h"

void test_sum() {
    TEST_ASSERT(sum(3, 6) == 9);
    TEST_ASSERT(sum(9, 12) == 21); 
}

void test_mod() {
    TEST_ASSERT(mod(6, 3) == 0);
    TEST_ASSERT(mod(9, 2) == 1);
    TEST_ASSERT(mod(7, 4) == 3);
}

TEST_LIST = { 
    { "test_sum", test_sum },
    { "test_mod", test_mod },
    { NULL, NULL}
};