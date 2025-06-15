#include <iostream>

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
