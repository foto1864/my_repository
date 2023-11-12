#include "my_stack.h"

// Default Constructor
template <class T>
Stack<T>::Stack() {
    start = NULL;   
    size = 0;                   
} 

// Constructor with Input. Creates the Stack and inserts 1 first element.
template <class T>
Stack<T>::Stack(T dataIn) {
    start = new ListNode;
    start->data = dataIn;
    size = 1;
}

// Copy Constructor .... TODO ...
template <class T>
Stack<T>::Stack(const Stack &st) {}
// Destructor .......... TODO ...
template <class T>
Stack<T>::~Stack() {}

// Inserts an element to the top of the stack.
template <class T>
bool Stack<T>::push(T dataIn) {
    ListNode* node = new ListNode;
    if (node == NULL)
        return false;
    node->data = dataIn;
    node->next = start;
    start = node;
    return true;
}

// Deletes an element from the top of the stack.
template <class T>
bool Stack<T>::pop(void) {
    if (isEmpty()) 
        return false;
    ListNode *temp = start->next;
    delete start;
    start = temp;
    size--;
    return true;
}

// Signifies whether the stack is empty or not.
template <class T>
bool Stack<T>::isEmpty(void) {
    if (size == 0)
        return true;
    return false;
}

// Returns the size of the Stack.
template <class T>
int Stack<T>::getSize(void) {
    return size;
}

// Returns the value of the first element of the Stack
template <class T>
T Stack<T>::getTop(void) {
    return start->data;
}

// Inserts the elements of stack s2 to the current Stack.
template <class T>
Stack<T> Stack<T>::operator+(Stack s2){
    while (!s2.isEmpty()){
        T data = s2.getTop();
        push(data);
        s2.pop();
    }
}