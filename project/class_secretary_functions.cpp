#include "include/class_secretary.h"
#include "include/class_person.h"

Secretary::Secretary() {
    cout << "University created." << endl;
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
    cout << "The university contains the following people:" << endl << endl;
    map<string, Person*>::const_iterator it;
    for (it = sec.university.begin(); it != sec.university.end(); it++) {
        Person *p = it->second;
        str << *p << endl;
    }
    return str;
}

Secretary Secretary::operator+(const Person& p) {
    Secretary sec = *this;
    string name = p.get_name();
    string email = p.get_email_address();
    string phone = p.get_phone_number();
    uint b_year = p.get_birth_year();
    uint id = p.get_academic_ID();
    Person *new_person = new Person(name, email, phone, b_year, id);
    sec.university[phone] = new_person;
    return sec;
}


istream &operator>>(istream &str, Secretary &sec) {
    cout << "How many people do you want to add to the university?" << endl;
    uint num_of_people;
    str >> num_of_people;

    for (uint i = 0; i < num_of_people; ++i) {
        cout << "Give Students' or Teachers' info in the following order: " << endl;
        cout << "Name, Academic ID, Phone Number, Birth Year Email Address." << endl;

        Person* person = new Person(); 
        string name, phone_num, email;
        uint id, b_year;
        str >> name;
        str >> id;
        str >> phone_num; 
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

Secretary Secretary::operator=(const Secretary &prev_sec) {
    
    // Since some members of the map inside the instance of object "Secretary" have been
    // statically inserted in the map (not dynamically allocated) there needs to be a 
    // condition in order to prevent a potential un-needed call of the delete function.
    map<string, Person*>::const_iterator it_01;
    for (it_01 = this->university.begin(); it_01 != this->university.end(); it_01++) {
        if (it_01->second != NULL)
            delete it_01->second;
    }

    // Now that the original map has been cleared, we dynamically allocate memory of all its
    // new members and add them to the map. Finally the function returns the new "Secretary"
    // object that will replace the old one after the call of the function.
    map<string, Person*>::const_iterator it_02;
    for (it_02 = prev_sec.university.begin(); it_02 != prev_sec.university.end(); it_02++) {
        string name = it_02->second->get_name();
        string email = it_02->second->get_email_address();
        string phone = it_02->second->get_phone_number();
        uint b_year = it_02->second->get_birth_year();
        uint id = it_02->second->get_academic_ID();
        Person *new_person = new Person(name, email, phone, b_year, id);       
        this->university[phone] = new_person;
    }

    return *this;
}

// Whenever an object of type "Secretary" is created with the use of the copy constructor,
// the memory of all of the members of the map of the new object is dynamically allocated. 
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


Secretary::~Secretary() {
    // Again we want to make sure that we free only the members of the map, the memory for
    // which has been dynamically allocated.
    map<string, Person*>::const_iterator it;
    for (it = university.begin(); it != university.end(); it++) {
        if (it->second != NULL)
            delete it->second;
    }
    cout << "University terminated." << endl;
}