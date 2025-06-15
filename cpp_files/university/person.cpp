#include "include/person.h"

int Person::count = 0;

// Mutator Functions
void Person::set_name(string n) { 
    name = n;
    return;
}
void Person::set_email_address(string email) { 
    email_address = email;
    return;
}
void Person::set_phone_number(string phone_num) { 
    phone_number = phone_num;
    return;
}
void Person::set_birth_year(uint year) { 
    birth_year = year;
    return;
}
void Person::set_academic_ID(uint id) { 
    academic_ID = id; 
    return; 
}

// Accessor Functions
string Person::get_name(void) const { 
    return name; 
}
string Person::get_email_address(void) const { 
    return email_address; 
}
string Person::get_phone_number(void) const { 
    return phone_number; 
}
uint Person::get_birth_year(void) const { 
    return birth_year; 
}
uint Person::get_academic_ID(void) const { 
    return academic_ID; 
}

// Operator Overloading
ostream &operator<<(ostream &str, Person &person) {
    str << person.name << " ";
    str << person.academic_ID << " ";
    str << person.phone_number << " ";
    str << person.birth_year << " ";
    str << person.email_address;
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
Person::Person() { 
    count++; 
} 
Person::Person(string n, uint id) : name(n), academic_ID(id) { 
    count++; 
}
Person::Person(string n, string email, string number, uint year, uint id) : 
        name(n), email_address(email), phone_number(number), birth_year(year), academic_ID(id) { 
        count++; 
}
Person::~Person() { 
    count--; 
}