#include "functions.h"



int main(void) {

    Node* root = initialize_tree();
    print_tree(root);
    free_tree_memory(root);
    return 0;
}