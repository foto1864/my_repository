#include <iostream>
using namespace std;
typedef unsigned int uint;
void printArray(char* array, uint size);
void deleteRepeats(char* array, uint size);

int main(void) {
    
    while (1) {

        uint arraySize;
        cout << "Please enter the size of the array: " << endl;
        cin >> arraySize;
        char* charArray = new char[arraySize];

        cout << "Enter the characters that will be put into the array: " << endl;
        for (int i=0; i<arraySize; i++) {
            cin >> charArray[i];
        }    

        cout << "Now the duplicate characters are going to be deleted from the array: " << endl;
        deleteRepeats(charArray, arraySize);            
        delete[] charArray;    
        
        char userReply;
        cout << "Would you like to repeat the process for a new array with different values?" << endl;
        cout << "Press 'N' or 'n' if you would like the process to stop, else press any key to repeat." << endl;

        cin >> userReply;
        if (userReply == 'N' || userReply == 'n') 
            break;
    }

    return 0;
}

void printArray(char* array, uint size) {
    for (int i=0; i<size; i++) {
        cout << array[i];
    }
    cout << endl;
    return;
}

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