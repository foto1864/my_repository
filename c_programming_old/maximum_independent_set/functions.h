// Library file functions.h, used for MIS.c 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef void* Pointer;
typedef struct Node {
    Pointer value;
    struct Node* left;
    struct Node* right;
} Node;
void print_tree(Node*);
void free_tree_memory(Node*);
Node* initialize_tree(void);
Node* new_node(Pointer);