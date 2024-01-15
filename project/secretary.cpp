#include "include/secretary.h"

Secretary::Secretary() {}

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

void Secretary::insert_course(Course *c) {
    uint course_id = c->course_get_id();
    string course_name = c->course_get_name();
    uint ECTs = c->course_get_ECTS();
    uint semester = c->course_get_semester();
    bool is_mandatory = c->course_is_mandatory();
    Course *new_course = new Course(course_id, course_name, semester, is_mandatory, ECTs);
    courses[course_name] = new_course;
}


bool Secretary::remove_professor(string phone_number) {
    if (professors.erase(phone_number) > 0) {
        return true;
    }
    return false;
}

bool Secretary::remove_student(string phone_number) {
    if (students.erase(phone_number) > 0) {
        return true;
    }
    return false;
}

bool Secretary::remove_course(string course_name) {
    if (courses.erase(course_name) > 0) {
        return true;
    }
    return false;
}


Student* Secretary::find_student_by_phone_number(string phone_number) {
    map<string, Student*>::iterator map_iterator;
    map_iterator = students.find(phone_number);
    return (map_iterator == students.end()) ? STUDENT_DOES_NOT_EXIST : map_iterator->second;
}
Student** Secretary::find_students_by_course(string course_name) {
    map<string, Student*>::iterator map_iterator;
    string course_name_in_map;
    Student **students_array = new Student*[students.size()];
    int i=0;
    for (map_iterator = students.begin(); map_iterator != students.end(); map_iterator++) {
       students_array[i] = map_iterator->second->student_has_joined_course(course_name);
       i++;
    }
    return students_array;
}


Professor* Secretary::find_professor(string phone_number) {
    map<string, Professor*>::iterator map_iterator;
    map_iterator = professors.find(phone_number);
    return (map_iterator == professors.end()) ? PROFESSOR_DOES_NOT_EXIST : map_iterator->second;
}
Course* Secretary::find_course(string course_name) {
    map<string, Course*>::iterator map_iterator;
    map_iterator = courses.find(course_name);
    return (map_iterator == courses.end()) ? COURSE_DOES_NOT_EXIST : map_iterator->second;
}

uint Secretary::size(void) {
    return professors.size() + students.size();
}

ostream &operator<<(ostream &str, const Secretary &sec){
    cout << "The university contains the following people:" << endl << endl;

    cout << "Professors:" << endl;
    map<string, Professor*>::const_iterator it;
    for (it = sec.professors.begin(); it != sec.professors.end(); it++) {
        Person *p = it->second;
        str << *p;
    }

    cout << endl << "Students:" << endl;
    map<string, Student*>::const_iterator it_2;
    for (it_2 = sec.students.begin(); it_2 != sec.students.end(); it_2++) {
        Person *p = it_2->second;
        str << *p;
    }
    return str;
}

Secretary Secretary::operator+(const Student& p) {
    Secretary sec = *this;
    string name = p.get_name();
    string email = p.get_email_address();
    string phone = p.get_phone_number();
    uint b_year = p.get_birth_year();
    uint id = p.get_academic_ID();
    uint years_joined = CURRENT_YEAR - (p.get_academic_ID())/100;
    Student *new_student = new Student(name, email, phone, b_year, id, years_joined);
    sec.students[phone] = new_student;
    return sec;
}

Secretary Secretary::operator+(const Professor& p) {
    Secretary sec = *this;
    string name = p.get_name();
    string email = p.get_email_address();
    string phone = p.get_phone_number();
    uint b_year = p.get_birth_year();
    uint id = p.get_academic_ID();
    uint years_experience = CURRENT_YEAR - (p.get_academic_ID())/100;
    Professor *new_professor = new Professor(name, email, phone, b_year, id, years_experience);
    sec.professors[phone] = new_professor;
    return sec;
}


istream &operator>>(istream &str, Secretary &sec) {
    cout << "How many people do you want to add to the university?" << endl;
    uint num_of_people;
    str >> num_of_people;

    for (uint i = 0; i < num_of_people; ++i) {
        cout << "Do you want to add a student(S/s) or a professor(P/p)?" << endl;

        char user_choice;
        cin >> user_choice;
        while (!(user_choice == 'S' || user_choice == 's' || user_choice == 'P' || user_choice == 'p')) {
            cout << "Invalid character entered" << endl;
            cin >> user_choice;
        }

        if (user_choice == 'S' || user_choice == 's') {
            cout << "Enter student's info in the following order:" << endl;
            cout << "Name, Academic ID, Phone Number, Birth Year Email Address." << endl;
            Student* student = new Student(); 
            string name, phone_num, email;
            uint id, b_year;
            str >> name;
            str >> id;
            str >> phone_num; 
            str >> b_year;
            str >> email;
            student->set_phone_number(phone_num);
            student->set_name(name);
            student->set_academic_ID(id);
            student->set_birth_year(b_year);
            student->set_email_address(email);
            student->set_years_joined(CURRENT_YEAR - (id/100));
            sec.students[student->get_phone_number()] = student;
        }

        else if (user_choice == 'P' || user_choice == 'p') {
            cout << "Enter professors's info in the following order:" << endl;
            cout << "Name, Academic ID, Phone Number, Birth Year Email Address." << endl;
            Professor* professor = new Professor(); 
            string name, phone_num, email;
            uint id, b_year;
            str >> name;
            str >> id;
            str >> phone_num; 
            str >> b_year;
            str >> email;
            professor->set_phone_number(phone_num);
            professor->set_name(name);
            professor->set_academic_ID(id);
            professor->set_birth_year(b_year);
            professor->set_email_address(email);
            professor->set_years_of_experience(CURRENT_YEAR - (id/100));
            sec.professors[professor->get_phone_number()] = professor;
        }
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
}