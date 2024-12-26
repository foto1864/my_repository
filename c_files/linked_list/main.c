#include "linked_list.h"

int main(void) {

    list *list = list_create();
    list_insert(list, 10);
    list_insert(list, 20);
    list_insert(list, 30);

    print_list(list);
    
    list_remove(list, 20);

    print_list(list);


    list_destroy(list);

    return 0;
}