// File: project_section_a.cpp

#include <iostream>
#include <cstdlib>
#include <map>
using namespace std;    

void show_menu(void);
void get_user_input(void);

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

class Student : public Person {
    private:
        uint year_joined_university;
    public:
        static int student_count;
        Student();
        Student(string, uint);
        Student(string, string, string, uint, uint);
        Student(string, string, string, uint, uint, uint);
        ~Student();
};

class Professor : public Person {
    private:
        uint years_of_experience;
    public:
        static int professor_count;
        Professor();
        Professor(string, uint);
        Professor(string, string, string, uint, uint);
        Professor(string, string, string, uint, uint, uint);
        ~Professor();
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
        Secretary operator=(const Secretary&);
        Secretary operator+(const Person&);
        Secretary();
        Secretary(const Secretary&);
        ~Secretary();
};

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////// MAIN FUNCTION ///////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

int main(void) {
    show_menu();
    get_user_input();
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// FUNCTIONS FOR CLASS PERSON /////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// FUNCTIONS FOR CLASS SECRETARY //////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// FUNCTIONS FOR CLASS PROFESSOR //////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

int Professor::professor_count = 0;

Professor::Professor() { professor_count++; }
Professor::Professor(string n,uint id) : Person(n, id) { professor_count++; }
Professor::Professor(string n, string email, string number, uint year, uint id) : Person(n,email,number,year,id) { professor_count++; }
Professor::Professor(string n, string email, string number, uint year, uint id, uint years_exp) 
        :Person(n,email,number,year,id), years_of_experience(years_exp) { professor_count++; }
Professor::~Professor() { professor_count--; }

///////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// FUNCTIONS FOR CLASS STUDENT ////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

int Student::student_count = 0;

Student::Student() { student_count++; }
Student::Student(string n,uint id) : Person(n, id) { student_count++; }
Student::Student(string n, string email, string number, uint year, uint id) : Person(n,email,number,year,id) { student_count++; }
Student::Student(string n, string email, string number, uint year, uint id, uint years_joined) 
        :Person(n,email,number,year,id), year_joined_university(years_joined) { student_count++; }
Student::~Student() { student_count--; }

///////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////// GENERAL FUNCTIONS /////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

void show_menu(void) {
    
    // Show the menu of options to the User
    cout << endl << "Welcome to our University! You have the following options:" << endl << endl;
    cout << "1) Add - Remove - Edit Professor" << endl;
    cout << "2) Add - Remove - Edit Student" << endl;
    cout << "3) Add - Remove - Edit Course" << endl;
    cout << "4) Set the professor of a course" << endl;
    cout << "5) Register to a course (for students only)" << endl;
    cout << "6) Print a list of the students that passed a course in the current semester" << endl; 
    cout << "7) Print the statistics for all courses in the current semester (for Professors only)" << endl;
    cout << "8) Print your average score (for students only)" << endl;
    cout << "9) Print a list of all the students that are eligible to graduate from the University" << endl << endl;
    cout << "You can select one of the options 1-9 by pressing the corresponding key." << endl;
    
}

void get_user_input(void) {
    
    // Get input from the user
    int count = 0;
    int pressed_key;
    cin >> pressed_key;
    while ((pressed_key > 9) || (pressed_key < 0)) {
        count++;  
        if (count < 5) 
            cout << "Invalid key entered. You can only select an option from 1-9." << endl;   
        else if (count >= 5) {
            pressed_key = 10;
            break;
        }
        cin >> pressed_key;
    }

    // Should that be a new func?
    // Call a function depending on the user's input
    switch (pressed_key) {
        case 1:
            cout << "Ton pairnoute?" << endl;
            break; 
        case 2:
            cout << "Ton pairnoute?" << endl;
            break;
        case 3:
            cout << "Ton pairnoute?" << endl;
            break;
        case 4:
            cout << "Ton pairnoute?" << endl;
            break;
        case 5:
            cout << "Ton pairnoute?" << endl;
            break;
        case 6:
            cout << "Ton pairnoute?" << endl;
            break;
        case 7:
            cout << "Ton pairnoute?" << endl;
            break;
        case 8:
            cout << "Ton pairnoute?" << endl;
            break;
        case 9:
            cout << "Ton pairnoute?" << endl;
            break;
        case 10:
            cout << "Too many failed attempts. Please try again later." << endl;
            break;
    }

}