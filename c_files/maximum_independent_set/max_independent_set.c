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
    printf("%d ", *(int*) root->value);
    if(root->left != NULL)
        print_tree(root->left);
    if(root->right != NULL)
        print_tree(root->right);
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

}

int main(void) {

    Node* root = initialize_tree();

    putchar(10);
    print_tree(root);
    putchar(10);
    return 0;
}