#include <iostream>
#include <cstdlib>
#define MIN_UNIVERSITY_SIZE 10
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
        int64_t get_phone_number(void);
        uint get_birth_year(void);
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

class Secretary {
    private:
        Person **university;
        uint university_capacity;
    public:
        uint university_size;
        void insert_person(Person *);
        Person** extend_university(Person **, uint);
        Secretary();
};

////////////////////////////////// FUNCTIONS FOR CLASS SECRETARY //////////////////////////////////

Secretary::Secretary() {
    university = (Person**) malloc(MIN_UNIVERSITY_SIZE*sizeof(Person*));
    for (int i=0; i<MIN_UNIVERSITY_SIZE; i++) {
        university[i] = NULL;
    }
    university_capacity = MIN_UNIVERSITY_SIZE;
    university_size = 0;
}

Person** Secretary::extend_university(Person **university, uint previous_capacity) {
    Person **newUniversity = (Person**) malloc(2*previous_capacity*sizeof(Person*));
    for (uint i=0; i<previous_capacity; i++) {
        newUniversity[i] = university[i];
    }
    for (uint i=0; i<previous_capacity; i++) {
        newUniversity[previous_capacity+i] = NULL;
    }
    free(university);
    return newUniversity;
}

void Secretary::insert_person(Person *p) {
    int pos = 0;
    int stop_loop;
    if (university_size > MIN_UNIVERSITY_SIZE)
        stop_loop = university_size;
    else 
        stop_loop = MIN_UNIVERSITY_SIZE;

    for (pos=0; pos < stop_loop; pos++) {
        if (university[pos] == NULL) break;
    }
    // This means that the person is going to be inserted at index pos
    university[pos] = p;
    university_size++;
    if (university_size * 2 > university_capacity) {
        university = extend_university(university, university_capacity);
        cout << "Resize happened!" << endl;
    }
}

// Do I need to use a given data structure or create my own one?
// Why does the second option seem easier bruv?

// There is no segfault in creating my own vector
// Because Im him




int main(void) {

    Person p1("Giannis", "foto@gmail.com", 6972521094, 2004, 2200207);
    cout << p1;

    Secretary university;
    Person **p = (Person**) malloc(sizeof(Person*));
    for (int i=0; i<20; i++) {
        p[i] = (Person*) malloc(sizeof(class Person));
    }

    for (int i=0; i<20; i++) {
        university.insert_person(p[i]);
    }

    return 0;
}



////////////////////////////////// FUNCTIONS FOR CLASS PERSON //////////////////////////////////

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