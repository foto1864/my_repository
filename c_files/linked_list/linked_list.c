#include "linked_list.h"

int print_list(list *list) {
    if (list == NULL) {
        fprintf(stderr, "List has not been initialized.\n");
        return -1;
    }
    list_node *temp = list->head;
    while (temp != NULL) {
        printf("%d -> ", temp->value);
        temp = temp->next;
    }
    printf("NULL\n"); 
    return 0;
}

list_node* create_node(int value) {
    list_node *n1 = (list_node *)malloc(sizeof(list_node));
    n1->value = value;
    n1->next = NULL;
    return n1;
}

int list_insert(list *list, int value) {

    if (list == NULL) {
        fprintf(stderr, "List has not been initialized.\n");
        return -1;
    }

    list_node *node = create_node(value);
    list_node *temp = list->head;
    list_node *previous = NULL;

    if (list->head == NULL) {
        list->head = node;
        list->size++;
        return 0;
    }

    while(temp != NULL) {
        previous = temp;
        temp = temp->next;
    }

    previous->next = node;
    list->size++;
    return 0;
}

int list_remove(list *list, int value) {
    // Special case: Removing the head of the list
    list_node *node = list->head;
    list_node *previous = NULL;

    if (list == NULL) {
        fprintf(stderr, "List has not been initialized.\n");
        return -1; 
    }

    if (node->value == value) {
        // If the head node is the one to remove
        list->head = node->next;
        free(node);
        list->size--;
        return 0; // Success
    }

    // Traverse the list to find the node to remove
    while (node != NULL && node->value != value) {
        previous = node;
        node = node->next;
    }

    // If the value is not found
    if (node == NULL) {
        return -1; // Indicate failure (value not found)
    }

    // Remove the node by updating the `next` pointer of the previous node
    previous->next = node->next;
    free(node);
    list->size--;

    return 0; // Success
}

list* list_create(void) {
    list* list = malloc(sizeof(list));
    list->head = NULL;
    list->size = 0;
    return list;
}

int list_destroy(list *list) {
    
    if (list == NULL) {
        fprintf(stderr, "List has not been initialized.\n");
        return -1;
    }
    
    list_node *node = list->head;
    while (node != NULL) {
        list_node *next = node->next;
        free(node);
        node = next;
    }
    free(list);
    return 0;
}