#include <stdio.h>
#include <stdlib.h>

typedef struct list_node {
    int value;
    struct list_node *next; 
} list_node;

typedef struct {
    int size;
    list_node *head;
} list;

int print_list(list *list);
list_node* create_node(int value);
int list_insert(list *list, int value);
int list_remove(list *list, int value);
list* list_create(void);
int list_destroy(list *list);
int list_find(list *list, int value);