#include "functions.h"

// Allocates memory for a node on the Heap and returns a pointer to said node
Node* new_node(Pointer data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->value = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Prints the tree using recursion, in DFS style
void print_tree(Node* root) {
    printf("%s\n", (char*) root->value);
    if(root->left != NULL) {
        printf("left:");
        print_tree(root->left);
    }
    if(root->right != NULL) {
        printf("right:");
        print_tree(root->right);
    }
    return;
}

// Initialization according to the graph in Exercise 3
Node* initialize_tree() {
    Node* node_A = new_node("A");
    Node* node_B = new_node("B");
    Node* node_C = new_node("C");
    Node* node_D = new_node("D");
    Node* node_E = new_node("E");
    Node* node_F = new_node("F");
    Node* node_G = new_node("G");
    Node* node_H = new_node("H");
    Node* node_I = new_node("I");

    node_F->left = node_H;
    node_F->right = node_I;
    node_C->right = node_F;
    node_A->right = node_C;
    node_E->left = node_G;
    node_B->right = node_E;
    node_B->left = node_D;
    node_A->left = node_B;

    return node_A;
}

// Frees the memory of a tree
void free_tree_memory(Node* root) {
    if(root->left != NULL)
        free_tree_memory(root->left);
    if(root->right != NULL)
        free_tree_memory(root->right);
    free(root);
}
