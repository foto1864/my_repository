#include <iostream>
#include <cstdlib>
#include <map>
using namespace std;    

class Person {
    private:
        string name;
        string email_address;
        string phone_number;
        uint birth_year;
        uint academic_ID;
    public:
        static int count;
        // Mutator Functions
        void set_name(string);
        void set_email_address(string );
        void set_phone_number(string);
        void set_birth_year(uint);
        void set_academic_ID(uint);
        // Accessor Functions
        string get_name(void) const;
        string get_email_address(void) const;
        string get_phone_number(void) const;
        uint get_birth_year(void) const;
        uint get_academic_ID(void) const;
        // Operator Overloading
        friend ostream &operator<<(ostream &, Person &);
        friend istream &operator>>(istream &, Person &);
        // Constructors And Destructor
        Person();
        Person(string, uint);
        Person(string, string, string, uint, uint);
        ~Person();
};

class Secretary {
    private:
        map<string, Person*> university;
    public:
        void insert_person(Person*);
        bool find(string);
        uint size(void);
        friend ostream &operator<<(ostream &, const Secretary&);
        friend istream &operator>>(istream &, Secretary&);
        void operator=(const Secretary&);
        Secretary operator+(const Person&);
        Secretary();
        Secretary(const Secretary&);
        ~Secretary();
};

////////////////////////////////// FUNCTIONS FOR CLASS SECRETARY //////////////////////////////////

Secretary::Secretary() {
    cout << "Secretary created." << endl;
}

Secretary::Secretary(const Secretary& prev_sec) {
    map<string, Person*>::const_iterator it;
    for (it = prev_sec.university.begin(); it != prev_sec.university.end(); it++) {
        string name = it->second->get_name();
        string email = it->second->get_email_address();
        string phone = it->second->get_phone_number();
        uint b_year = it->second->get_birth_year();
        uint id = it->second->get_academic_ID();
        Person *new_person = new Person(name, email, phone, b_year, id);       
        university[phone] = new_person;
    }
}

void Secretary::insert_person(Person *p) {
    string name = p->get_name();
    string email = p->get_email_address();
    string phone = p->get_phone_number();
    uint b_year = p->get_birth_year();
    uint id = p->get_academic_ID();
    Person *new_person = new Person(name, email, phone, b_year, id);
    university[phone] = new_person;
}

bool Secretary::find(string phone_number) {
    map<string, Person*>::iterator map_iterator;
    map_iterator = university.find(phone_number);
    return map_iterator != university.end();
}

uint Secretary::size(void) {
    return university.size();
}

ostream &operator<<(ostream &str, const Secretary &sec){
    map<string, Person*>::const_iterator it;
    for (it = sec.university.begin(); it != sec.university.end(); it++) {
        Person *p = it->second;
        str << *p << endl;
    }
    return str;
}

Secretary Secretary::operator+(const Person& p) {
    Secretary sec = *this;
    Person *new_person = new Person;
    new_person->set_name(p.get_name());
    new_person->set_academic_ID(p.get_academic_ID());
    new_person->set_birth_year(p.get_birth_year());
    new_person->set_email_address(p.get_email_address());
    new_person->set_phone_number(p.get_phone_number());
    sec.university[p.get_phone_number()] = new_person;
    return sec;
}


istream &operator>>(istream &str, Secretary &sec) {
    cout << "How many people do you want to add to the university?" << endl;
    uint num_of_people;
    str >> num_of_people;

    for (int i = 0; i < num_of_people; ++i) {
        cout << "Give Students' or Teachers' info in the following order: " << endl;
        cout << "Name, Academic ID, Phone Number, Birth Year Email Address." << endl;

        Person* person = new Person(); // Create a new Person object
        string name, phone_num, email;
        uint id, b_year;
        str >> name;
        str >> id;
        str >>  phone_num; // Use the overloaded >> operator for Person
        str >> b_year;
        str >> email;
        person->set_phone_number(phone_num);
        person->set_name(name);
        person->set_academic_ID(id);
        person->set_birth_year(b_year);
        person->set_email_address(email);
        sec.university[person->get_phone_number()] = person;
    }
    return str;
}

Secretary::~Secretary() {
    map<string, Person*>::const_iterator it;
    for (it = university.begin(); it != university.end(); it++) {
        if (it->second != NULL)
            delete it->second;
    }
    cout << "Secretary destroyed." << endl;
}

int main(void) {

    Person p1("Giannis", "foto@gmail.com", "6912345432", 2004, 2200207);
    cout << p1 << endl;

    Person p2;
    cin >> p2;

    Secretary sec;
    sec.insert_person(&p1);
    sec.insert_person(&p2);
    
    cin >> sec;

    Person p3("Petros", "petros@mail.com", "6972521094", 2004, 2200208);

    cout << sec;
    
    if (sec.find("6912345432"))
        cout << "Found!" << endl;
    else 
        cout << "Not Found!" << endl;

    cout << "Size of secretary is " << sec.size() << endl;

    Secretary sec2 = sec;
    cout << sec2;

    return 0;
}



////////////////////////////////// FUNCTIONS FOR CLASS PERSON //////////////////////////////////

int Person::count = 0;

// Mutator Functions
void Person::set_name(string n) { name = n; return; }
void Person::set_email_address(string email) { email_address = email; return; }
void Person::set_phone_number(string phone_num) { phone_number = phone_num; return; }
void Person::set_birth_year(uint year) { birth_year = year; return; }
void Person::set_academic_ID(uint id) { academic_ID = id; return; }

// Accessor Functions
string Person::get_name(void) const { return name; }
string Person::get_email_address(void) const { return email_address; }
string Person::get_phone_number(void) const { return phone_number; }
uint Person::get_birth_year(void) const { return birth_year; }
uint Person::get_academic_ID(void) const { return academic_ID; }

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
Person::Person(string n, string email, string number, uint year, uint id) : 
        name(n), email_address(email), phone_number(number), birth_year(year), academic_ID(id) { count++; }
Person::~Person() { count--; }