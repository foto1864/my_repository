#include <stdio.h>
#include <stdlib.h>

typedef struct stack* Stack;
typedef struct stack_node* StackNode;
typedef void* Pointer;

// Functions for stack

Stack stack_create(void);
Stack stack_pop(Stack stack);
Stack stack_push(Stack stack, StackNode node);
int stack_get_size(Stack stack);
void stack_destroy(Stack stack, void (*destroy_value)(Pointer));

// Functions for nodes of stack

StackNode node_create(Pointer value);
StackNode stack_get_head(Stack stack);