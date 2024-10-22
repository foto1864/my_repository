#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int money_value;
    struct Node* next;
} Node;

Node* create_node(int value, Node* next) {
    Node* new_node = malloc(sizeof(*new_node));
    new_node->money_value = value;
    new_node->next = next;
    return new_node;
}

void print_node(Node* node) {
    printf("The money value of the node is %d\n", node->money_value);
    return;
}

int main() {

    Node* node = create_node(10, NULL);
    print_node(node);
    free(node);
    
    return 0;
}