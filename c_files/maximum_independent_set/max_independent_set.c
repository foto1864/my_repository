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
    printf("%s ", (char*)root->value);
    if(root->left != NULL)
        print_tree(root->left);
    if(root->right != NULL)
        print_tree(root->right);
    return;
}

Node* initialize_tree() {
    Node* root = new_node("A");
    Node* left = new_node("B");
    Node* right = new_node("C");
    Node* left_left = new_node("D");
    Node* left_right = new_node("E");
    Node* right_left = new_node("F");
    Node* right_right = new_node("G");

    right->right = right_right;
    right->left = right_left;
    left->left = left_left;
    left->right = left_right;
    root->left = left;
    root->right = right;

    return root;
}

int main(void) {

    Node* root = initialize_tree();

    putchar(10);
    print_tree(root);
    putchar(10);
    return 0;
}