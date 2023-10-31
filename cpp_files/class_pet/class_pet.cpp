#include <iostream>
using namespace std;

class Pet {
    private:
        string name;
        string species;
        int age;
    public:
        void setSpecies(string s) { species = s; }
        void setName(string n) { name = n; }
        void setAge(int a) {
            if (age < 0) {
                age = 0;
            }
            age = a;
        }
        int getAge() { return age; }
        string getName() { return name; }
        string getSpecies() {return species; }
        // Constructor
        Pet(string n, int a, string s) {
            name = n;
            age = a;
            species = s;
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

    Pet Noisette("Noisette", 10, "Dog");
    Pet Goofy("Goofy", 100, "Dog");
    Pet Mikey("Mikey", 100, "Mouse");

    cout << "The three pets have been created: Their names are:" << endl;
    cout << Noisette.getName() << ", " << Goofy.getName() << " and " << Mikey.getName() << endl;

    return 0;
}