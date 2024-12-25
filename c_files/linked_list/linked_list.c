#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int* next;
} *ListNode;

typedef struct {
    int size;
    ListNode first;
    ListNode last;
} *List;

List list_create() {
    List list = malloc(sizeof(*list));
    list->size = 1;
    list->first = NULL;
    list->last = NULL;
    return list;
}

ListNode create_node(int value) {
    ListNode node = malloc(sizeof(*node));
    node->value = value;
    node->next = NULL;
    return node;
}

void list_insert(List list, int value) {
    
    ListNode new_node = create_node(value);

    if (list->first == list->last) {
        list->first = new_node;
    }   
    else {
        list->last = new_node;
    }

    list->size++;

    return;
}

void list_print(List list) {
    if (list->first == NULL)
        return;
}

int main(void) {
    List list = list_create(10);
    list_print(list);
    return 0;
}