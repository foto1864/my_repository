#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void* Pointer;

typedef struct Node {
    Pointer value;
    struct Node* left;
    struct Node* right;
} Node;

Node* new_node(Pointer data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->value = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

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

void free_node(Node* node) {
    free(node->value);
    free(node);
}

void free_tree_memory(Node* root) {
    if(root->left != NULL)
        free_tree_memory(root->left);
    if(root->right != NULL)
        free_tree_memory(root->right);
    free_node(root);
}

int main(void) {

    Node* root = initialize_tree();

    putchar(10);
    print_tree(root);
    putchar(10);

    free_tree_memory(root);
    free(root);
    return 0;
}