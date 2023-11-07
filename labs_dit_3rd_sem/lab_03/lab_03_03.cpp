#include <iostream>
using namespace std;
const int MAX_SIZE = 1024;

int strlen(char *str) {
    int length = 0; 
    int i=0;
    while(1) {
        if (str[i] = '\0')
            break;
        length++;
        i++;
    }
    return length;
}

class String {
    private:
        char *array;
        int capacity;
        int size;
    public:
        String() {
            array = new char[MAX_SIZE];
            for (int i=0; i<MAX_SIZE; i++)
                array[i] = '\0';
            capacity = MAX_SIZE;
            size = 0;
        }
        String(int newCapacity, char str[]) {
            array = new char[newCapacity+1];
            for (int i=0; i<newCapacity; i++)
                array[i] = str[i];
            array[newCapacity] = '\0';
            size = capacity = newCapacity;
        }
        ~String() {
            delete[] array;
        }
        char *getStr(void) {
            return array;
        }
        int getSize(void) {
            return size;
        }
        int getCapacity(void) {
            return capacity;
        }
        char characterAtIndex(int index) {
            if (index > size)
                return '\0';
            return array[index];
        }
        void setString(char *str) {
            //size = strlen(str);
            //delete[] array;
            //array = new char[size+1];
            //capacity = size;
            for (int i=0; i<size; i++) 
                array[i] = str[i];
            array[size] = '\0';
        }
};


int main(void) {
    String str(11, "Hello World");
    char* check = str.getStr();
    cout << check << endl;
    char c = str.characterAtIndex(9);
    cout << "Character at index 9 is " << c << endl;
    cout << "Size of str is " << str.getSize() << endl;

    String str2;
    str2.setString("My name is Giannis Foteinakis");
    char* check2 = str2.getStr();
    cout << "Str2 says: " << check2 << endl;  
    return 0;
}