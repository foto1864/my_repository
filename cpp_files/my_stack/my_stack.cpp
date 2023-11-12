#include <iostream>
using namespace std;

template <class T>
class Stack {
    class ListNode {
        public: 
            T data;             // Contains the data of the Node.
            ListNode* next;     // Pointer to the next Node.
    };
    ListNode *start;
    int size;
    public:
        Stack();                    // Constructor.
        Stack(T dataIn);            // Constructor with input.
        Stack(const Stack &st);     // Copy Constructor.
        ~Stack();                   // Destructor.
        bool push(T dataIn);        // Inserts an element to the stack.
        bool pop(void);             // Deletes the first element of the stack.
        bool isEmpty(void);         // Signifies whether the stack is empty or not.
        int getSize(void);          // Returns the size of the stack.
        T getTop(void);             // Return the first element of the stack.
        Stack operator+(Stack s2);  // Adds the elements of s2 to the current stack.
};

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

int main(void) {
    cout << "Makefile Works" << endl;
    return 0;
}