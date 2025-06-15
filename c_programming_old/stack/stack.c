#include "stack.h"

struct stack {
    int size;
    StackNode head;
};

struct stack_node {
    Pointer value;
    StackNode next;
};

/* Regarding the Stack*/

Stack stack_create(void) {
    Stack stack = malloc(sizeof(*stack));
    stack->size = 0;
    stack->head = NULL;
    return stack;
}

Stack stack_push(Stack stack, StackNode node) {
    node->next = stack->head;
    stack->head = node;
    stack->size++;
    return stack;
}

Stack stack_pop(Stack stack) {
    if (stack->size == 0) {
        return stack;
    }
    StackNode temp = stack->head;
    stack->head = stack->head->next;
    free(temp);
    stack->size--;
    return stack;
}

int stack_get_size(Stack stack) {
    return stack->size;
}

void stack_destroy(Stack stack, void (*destroy_value)(Pointer)) {
    while (stack->size > 0) {
        StackNode temp = stack->head;
        stack->head = temp->next;
        if (destroy_value) {
            destroy_value(temp->value); 
        }
        free(temp);
        stack->size--;
    }
    free(stack);
}


/* Regarding the node*/

StackNode node_create(Pointer value) {
    StackNode node = malloc(sizeof(*node));
    node->value = value;
    node->next = NULL;
    return node;
}

StackNode stack_get_head(Stack stack) {
    return stack->head;
}