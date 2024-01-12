#include "include/class_secretary.h"
#include "include/class_person.h"
#include "include/class_student.h"
#include "include/class_professor.h"

Secretary::Secretary() {
    cout << "University created." << endl;
}

void Secretary::insert_student(Student *p) {
    string name = p->get_name();
    string email = p->get_email_address();
    string phone = p->get_phone_number();
    uint b_year = p->get_birth_year();
    uint id = p->get_academic_ID();
    uint years_of_experience = p->get_years_joined();
    Student *new_student = new Student(name, email, phone, b_year, id, years_of_experience);
    students[phone] = new_student;
}

void Secretary::insert_professor(Professor *p) {
    string name = p->get_name();
    string email = p->get_email_address();
    string phone = p->get_phone_number();
    uint b_year = p->get_birth_year();
    uint id = p->get_academic_ID();
    uint years_of_experience = p->get_years_experience();
    Professor *new_professor = new Professor(name, email, phone, b_year, id, years_of_experience);
    professors[phone] = new_professor;
}

bool Secretary::find(string phone_number) {
    map<string, Person*>::iterator map_iterator;
    map_iterator = university.find(phone_number);
    return map_iterator != university.end();
}

uint Secretary::size(void) {
    return professors.size() + students.size();
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
    map<string, Student*>::const_iterator it_00;
    for (it_00 = this->students.begin(); it_00 != this->students.end(); it_00++) {
        if (it_00->second != NULL)
            delete it_00->second;
    }
    
    map<string, Professor*>::const_iterator it_01;
    for (it_01 = this->professors.begin(); it_01 != this->professors.end(); it_01++) {
        if (it_01->second != NULL)
            delete it_01->second;
    }

    // Now that the original map has been cleared, we dynamically allocate memory of all its
    // new members and add them to the map. Finally the function returns the new "Secretary"
    // object that will replace the old one after the call of the function.
    map<string, Student*>::const_iterator it_02;
    for (it_02 = prev_sec.students.begin(); it_02 != prev_sec.students.end(); it_02++) {
        string name = it_02->second->get_name();
        string email = it_02->second->get_email_address();
        string phone = it_02->second->get_phone_number();
        uint b_year = it_02->second->get_birth_year();
        uint id = it_02->second->get_academic_ID();
        uint years_joined = it_02->second->get_years_joined();
        Student *new_student = new Student(name, email, phone, b_year, id, years_joined);       
        this->students[phone] = new_student;
    }

    map<string, Professor*>::const_iterator it_03;
    for (it_03 = prev_sec.professors.begin(); it_03 != prev_sec.professors.end(); it_03++) {
        string name = it_03->second->get_name();
        string email = it_03->second->get_email_address();
        string phone = it_03->second->get_phone_number();
        uint b_year = it_03->second->get_birth_year();
        uint id = it_03->second->get_academic_ID();
        uint years_exprerience = it_03->second->get_years_experience();
        Professor *new_professor = new Professor(name, email, phone, b_year, id, years_exprerience);       
        this->professors[phone] = new_professor;
    }

    return *this;
}

// Whenever an object of type "Secretary" is created with the use of the copy constructor,
// the memory of all of the members of the map of the new object is dynamically allocated. 
Secretary::Secretary(const Secretary& prev_sec) {
    
    // Copy-Paste the students
    map<string, Student*>::const_iterator it;
    for (it = prev_sec.students.begin(); it != prev_sec.students.end(); it++) {
        string name = it->second->get_name();
        string email = it->second->get_email_address();
        string phone = it->second->get_phone_number();
        uint b_year = it->second->get_birth_year();
        uint id = it->second->get_academic_ID();
        uint years_joined_university = it->second->get_years_joined();
        Student *new_student = new Student(name, email, phone, b_year, id, years_joined_university);       
        students[phone] = new_student;
    }

    // Copy-Paste the professors
    map<string, Professor*>::const_iterator it_2;
    for (it_2 = prev_sec.professors.begin(); it_2 != prev_sec.professors.end(); it_2++) {
        string name = it_2->second->get_name();
        string email = it_2->second->get_email_address();
        string phone = it_2->second->get_phone_number();
        uint b_year = it_2->second->get_birth_year();
        uint id = it_2->second->get_academic_ID();
        uint years_experience = it_2->second->get_years_experience();
        Professor *new_professor = new Professor(name, email, phone, b_year, id, years_experience);       
        professors[phone] = new_professor;
    }
}


Secretary::~Secretary() {
    // Again we want to make sure that we free only the members of the map, the memory for
    // which has been dynamically allocated.
    map<string, Professor*>::const_iterator it;
    for (it = professors.begin(); it != professors.end(); it++) {
        if (it->second != NULL)
            delete it->second;
    }
    map<string, Student*>::const_iterator it_2;
    for (it_2 = students.begin(); it_2 != students.end(); it_2++) {
        if (it_2->second != NULL)
            delete it_2->second;
    }
    cout << "University terminated." << endl;

}