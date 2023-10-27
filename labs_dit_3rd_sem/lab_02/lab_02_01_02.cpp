#include <iostream>
using namespace std;
typedef unsigned int uint;
void printArray(char* array, uint size);
void deleteRepeats(char* array, uint size);
void readArray(void);

int main(void) {
    while (1) {
        readArray();     
        cout << "Would you like to repeat the process for a new array with different values?" << endl;
        cout << "Press 'N' or 'n' if you would like the process to stop, else press any key to repeat." << endl;
        char userReply;
        cin >> userReply;        
        if (userReply == 'N' || userReply == 'n') 
            break;
    }
    return 0;
}

// Reads the size of the array and the contents of it
void readArray(void) {   
    uint arraySize;
    cout << "Please enter the size of the array: " << endl;
    cin >> arraySize;
    char* charArray = new char[arraySize];
    cout << "Please enter the characters that will be put into the array: " << endl;
    for (int i=0; i<arraySize; i++) {
        cin >> charArray[i];
    }
    deleteRepeats(charArray, arraySize);
    delete[] charArray;
}

// Deletes the duplicate characters in the array
void deleteRepeats(char* array, uint size) {
    for (int i = 0; i < size; i ++)  {
        for (int j = i + 1; j < size; j++) {  
            if (array[i] == array[j])  {  
                for (int k = j; k < size - 1; k++)  {  
                    array[k] = array[k + 1];  
                }  
                size--;  
                j--;   
                printArray(array, size);   
            }  
        }
    }
    return;  
}

// Prints the contents of the array
void printArray(char* array, uint size) {
    for (int i=0; i<size; i++) {
        cout << array[i];
    }
    cout << endl;
    return;
}