#include <iostream>
using namespace std;

class Person {
    private:
        string name;
        Pet *pet;
    public:
        void setName(string n);
        void getPet(void);
};

class Pet {
    private:
        string name;
        Person *owner;
    public:
        void setName(string n);
        void setOwner(Person *newOwner);
};

////////////////////////// Functions of class Person //////////////////////////
void Person::getPet(void) {
    Pet *pet = new Pet;
    pet->setOwner(this);
}
void Person::setName(string n) {
    name = n;
    return;
}

////////////////////////// Functions of class Pet //////////////////////////
void Pet::setOwner(Person *newOwner) {
    owner = newOwner;
    return;
}
void Pet::setName(string n) {
    name = n;
    return;
}

int main(void) {

    Person Giannis;
    Giannis.setName("Giannis");
    Pet Noisette;
    Noisette.setName("Noisette");
    Noisette.setOwner(&Giannis);
    Giannis.getPet();


    return 0;
}