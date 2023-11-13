#include <iostream>
#include "my_stack.h"
using namespace std;

int main(void) {
    
    cout << "Makefile Works" << endl;
    cout << "New Screen Works!" << endl;

    Stack<int> st;      // Create a stack to store ints
    int first = 5, second = 10, third = 15;
    st.push(first);
    st.push(second);
    st.push(third);

    if (!st.isEmpty()) {
        cout << "The stack is not empty!" << endl;
        cout << "The Stack has size " << st.getSize() << "." << endl;
    }

    int top = st.getTop();
    cout << "The top element of the stack is " << top << "." << endl;

    int size = st.getSize();
    for (int i=0; i<size; i++)
        st.pop();
    
    cout << "After clearing the stack it should be empty, with size " << st.getSize();
    
    if (st.isEmpty())
        cout << "Stack is indeed empty by check." << endl;

    return 0;
}