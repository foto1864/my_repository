#include <iostream>
using namespace std;

class Pet {
    private:
        string name;
        int age;
    public:
        void setName(string n) { name = n; }
        void setAge(int a) {
            if (age < 0) {
                age = 0;
            }
            age = a;
        }
        int getAge() { return age; }
        string getName() { return name;
        }
        // Constructor
        Pet(string n, int a) {
            name = n;
            age = a;
        }
        // Constructor Default
        Pet() {
            name = "Unknown";
            age = 0;
        }
        // Destructor 
        ~Pet() {
            cout << "Destructor for class Pet has been executed" << endl;
        }
    
};

int main(void) {

}