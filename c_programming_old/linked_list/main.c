#include "linked_list.h"
#include <time.h>

int main(void) {

    srand(time(NULL));
    
    list *list = list_create();

    int value_to_remove_1, value_to_remove_2 = 0;

    for (int i=0; i<20; i++) {
        int value = rand() % 100;
        list_insert(list, value);
        if (i==5) {
            value_to_remove_1 = value;
        }
        if (i==7) {
            value_to_remove_2 = value;
        }
    }

    print_list(list);
    
    int search_int = rand() % 100;

    int found = list_find(list, search_int);
    if (found == 0) {
        printf("%d is found in the list\n", search_int);
    }
    else {
        printf("%d is not found and list_find returned %d\n", search_int, found);
    }

    list_remove(list, value_to_remove_1);
    list_remove(list, value_to_remove_2);

    print_list(list);

    found = list_find(list, value_to_remove_1);
    if (found == 0) {
        printf("%d is found\n", value_to_remove_1);
    }
    else {
        printf("%d is not found and list_find returned %d\n", value_to_remove_1,found);
    }


    list_destroy(list);


    return 0;
}