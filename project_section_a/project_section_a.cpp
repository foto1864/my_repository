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
        string get_name(void);
        string get_email_address(void);
        string get_phone_number(void);
        uint get_birth_year(void);
        uint get_academic_ID(void);
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
        void operator=(const Secretary &);
        Secretary operator+(const Secretary &);
        Secretary();
        Secretary(const Secretary &);
        ~Secretary();
};

////////////////////////////////// FUNCTIONS FOR CLASS SECRETARY //////////////////////////////////

Secretary::Secretary() {
    cout << "Secretary created." << endl;
}

void Secretary::insert_person(Person *p) {
    university.insert(pair<string, Person*> (p->get_phone_number(), p));
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


istream &operator>>(istream &str, Secretary &sec) {
    return str;
}

Secretary::~Secretary() {
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

    cout << sec;
    

    if (sec.find("6912345432"))
        cout << "Found!" << endl;
    else 
        cout << "Not Found!" << endl;

    cout << "Size of secretary is " << sec.size() << endl;


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
string Person::get_name(void) { return name; }
string Person::get_email_address(void) { return email_address; }
string Person::get_phone_number(void) { return phone_number; }
uint Person::get_birth_year(void) { return birth_year; }
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
Person::Person(string n, string email, string number, uint year, uint id) : 
        name(n), email_address(email), phone_number(number), birth_year(year), academic_ID(id) { count++; }
Person::~Person() { count--; }