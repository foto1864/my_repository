#include <iostream>
using namespace std;

class Pet {
    private:
        string name;
        int age;
    public:
        void setName(string n) {
            name = n;
        }
        void setAge(int a) {
            if (age < 0) {
                age = 0;
            }
            age = a;
        }
        int getAge() {
            return age;
        }
        string getName() {
            return name;
        }
        Pet(string n, int a) {
            name = n;
            age = a;
        }
        Pet() {
            name = "Unknown";
            age = 0;
        }
    
};

int main(void) {

}