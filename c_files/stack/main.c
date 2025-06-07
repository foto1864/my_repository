#include "stack.h"
#include <string.h>

int main(void) {
   
    while(1) {
    
        Stack stack = stack_create();

        char buf[100];
        fgets(buf, sizeof(buf), stdin);
        printf("String was: %s\n", buf);

        for (int i=0; i<strlen(buf)-1; i++) {
            if (buf[i] == 'a') {
                StackNode node = node_create("X");
                stack = stack_push(stack, node);
            }
            else if (buf[i] == 'b') {
                stack = stack_pop(stack);
            }
            else {
                printf("You are trying to break us aren't you?\n");
                break;
            }
        }

        int size = stack_get_size(stack);
        if (size == 0) {
            printf("String is contained in L\n");
        }
        else {
            printf("String is not contained in L\n");
        }
        stack_destroy(stack, NULL);

    }
   
    return 0;
}