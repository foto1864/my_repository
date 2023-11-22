#include <iostream>
#include <iterator>
#include <map>
using namespace std;

class Person {
    private:
        string name;
        string email_address;
        int64_t phone_number;
        uint birth_year;
        uint academic_ID;
    public:
        static int count;
        // Mutator Functions
        void set_name(string n);
        void set_email_address(string email);
        void set_birth_year(uint year);
        void set_phone_number(uint number);
        void set_academic_ID(uint id);
        // Accessor Functions
        string get_name(void);
        string get_email_address(void);
        uint get_birth_year(void);
        int64_t get_phone_number(void);
        uint get_academic_ID(void);
        // Operator Overloading
        friend ostream &operator<<(ostream &str, Person &person);
        friend istream &operator>>(istream &str, Person &person);
        // Constructors And Destructor
        Person();
        Person(string, uint);
        Person(string, string, int64_t, uint, uint);
        ~Person();
};

////////////////////////////////// FUNCTIONS FOR CLASS PERSON ////////////////////////////
int Person::count = 0;
// Mutator Functions
void Person::set_name(string n) { name = n; return; }
void Person::set_email_address(string email) { email_address = email; return; }
void Person::set_birth_year(uint year) { birth_year = year; return; }
void Person::set_phone_number(uint number) { phone_number = number; return; }
void Person::set_academic_ID(uint id) { academic_ID = id; return; }
// Accessor Functions
string Person::get_name(void) { return name; }
string Person::get_email_address(void) { return email_address; }
uint Person::get_birth_year(void) { return birth_year; }
int64_t Person::get_phone_number(void) { return phone_number; }
uint Person::get_academic_ID(void) { return academic_ID; }
// Operator Overloading
ostream &operator<<(ostream &str, Person &person) {
    str << person.name << endl;
    str << person.academic_ID << endl;
    str << person.phone_number << endl;
    str << person.birth_year << endl;
    str << person.email_address << endl;
    return str;
}
istream &operator>>(istream &str, Person &person) {
    cout << "Give Student's or Teacher's info in the following order: " << endl;
    cout << "Name, Academic ID, Phone Number, Birth Year Email Address." << endl;
    str >> person.name;
    str >> person.academic_ID;
    str >> person.phone_number;
    str >> person.birth_year;
    str >> person.email_address;
    return str;
}
// Constructors And Destructor
Person::Person() { count++; } 
Person::Person(string n, uint id) : name(n), academic_ID(id) { count++; }
Person::Person(string n, string email, int64_t number, uint year, uint id) : 
        name(n), email_address(email), phone_number(number), birth_year(year), academic_ID(id) { count++; }
Person::~Person() { count--; }


class Secretary {
    private:
        map<uint, Person*> university;
    public:
        void insert_person(Person*);
        void remove_person(Person*);
        uint get_university_size(void);
        Person* find_person(uint);
};

void Secretary::insert_person(Person *p) {
    university.insert(pair<uint, Person*> (p->get_academic_ID(), p));
}
void Secretary::remove_person(Person *p) {
    university.erase(p->get_academic_ID());
}
Person* Secretary::find_person(uint id) {
    auto variable = university.find(id);
    Person *p = NULL;
    return p;
}
uint Secretary::get_university_size(void) {
    return university.size();
}


int main(void) {

    Person p1("Giannis", "foto@gmail.com", 6972521094, 2004, 2200207);
    cout << p1;

    Person *pp1 = &p1;

    Secretary secretary;
    secretary.insert_person(pp1);
    cout << "Size is " << secretary.get_university_size() << endl;
    secretary.remove_person(pp1);
    cout << "Size is " << secretary.get_university_size() << endl;
    
    return 0;
}