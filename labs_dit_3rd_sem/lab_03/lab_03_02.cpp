#include <iostream>
using namespace std;

class Person {
    private:
        string name;
        Pet *pet;
    public:
        void setName(string n);
        void getPet(Pet *newPet);
        string getPetName(void);
};

class Pet {
    private:
        string name;
        Person *owner;
    public:
        void setName(string n);
        void setOwner(Person *newOwner);
        string getName(void);
};

////////////////////////// Functions of class Person //////////////////////////
void Person::getPet(Pet *newPet) {
    newPet->setOwner(this);
}
void Person::setName(string n) {
    name = n;
    return;
}
string Person::getPetName(void) {
    return pet->getName();
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
string Pet::getName(void) {
    return name;
}

int main(void) {

    Person foto;
    foto.setName("Foto");
    Pet dog;
    dog.setName("Serpico");
    foto.getPet(&dog);

    cout << "Foto's dog is " << foto.getPetName() << endl;

    return 0;
}