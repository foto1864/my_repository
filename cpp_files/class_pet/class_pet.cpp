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

    Pet Noisette("Noisette", 10);
    Pet Goofy("Goofy", 100);
    Pet Mikey("Mikey", 100);

    cout << "The three pets have been created: Their names are:" << endl;
    cout << Noisette.getName() << ", " << Goofy.getName() << " and " << Mikey.getName() << endl;

    return 0;
}