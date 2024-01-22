#include "include/secretary.h"
#include "include/utilities.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// FUNCTIONS OF THE UNIVERSITY MENU //////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////

// 01. Add - Edit - Remove Professor
void Secretary::add_edit_remove_professor(void) {
    cout << "Do you want to 1) add, 2) edit or 3) remove a professor from the university?" << endl;
    cout << "Select the option you want by pressing one of the above keys, 1,2 or 3." << endl;
    int key = get_user_input(1,3);
    // Add Professor
    if (key == ADD) {
        Professor new_professor;
        cin >> new_professor;
        this->insert_professor(&new_professor);
    }
    // Edit Professor
    else if (key == EDIT) {
        cout << "You can edit a professor by changing their phone_number." << endl;
        cout << "Type in the phone number of the professor you want to edit." << endl;
        string phone_number;
        cin >> phone_number;
        Professor *old_professor = this->find_professor(phone_number);
        if (old_professor == PROFESSOR_DOES_NOT_EXIST) {
            cout << "There does not exist a professor with such a phone number in the university." << endl;
            return;
        }
        cout << "Type in the new phone number of the professor." << endl;
        string new_phone_number;
        cin >> new_phone_number;
        Professor new_professor = *old_professor;
        new_professor.set_phone_number(new_phone_number);
        this->insert_professor(&new_professor);
        this->remove_professor(phone_number);
        cout << "The change of the phone number of the professor was successful." << endl;

    }
    // Remove Professor
    else if (key == REMOVE) {
        cout << "Type in the phone number of the professor you want to remove from the university" << endl;
        string phone_number;
        cin >> phone_number;
        Professor *professor = this->find_professor(phone_number);
        if (professor == PROFESSOR_DOES_NOT_EXIST) {
            cout << "There does not exist a professor with such a phone number in the university." << endl;
            return;
        }
        this->remove_professor(phone_number);
        cout << "Removal of Professor was successful." << endl;
    }
    return;
}

// 02. Add - Edit - Remove Student
void Secretary::add_edit_remove_student(void) {
    cout << "Do you want to 1) add, 2) edit or 3) remove a student from the university?" << endl;
    cout << "Select the option you want by pressing one of the above keys, 1,2 or 3." << endl;
    int key = get_user_input(1,3);
    // Add student
    if (key == ADD) {
        Student new_student;
        cin >> new_student;
        this->insert_student(&new_student);
    }
    // Edit Student
    else if (key == EDIT) {
        cout << "You can edit a student by changing their phone_number." << endl;
        cout << "Type in the phone number of the student you want to edit." << endl;
        string phone_number;
        cin >> phone_number;
        Student *old_student = this->find_student_by_phone_number(phone_number);
        if (old_student == STUDENT_DOES_NOT_EXIST) {
            cout << "There does not exist a student with such a phone number in the university." << endl;
            return;
        }
        cout << "Type in the new phone number of the student." << endl;
        string new_phone_number;
        cin >> new_phone_number;
        Student new_student = *old_student;
        new_student.set_phone_number(new_phone_number);
        this->insert_student(&new_student);
        this->remove_student(phone_number);
        cout << "The change of the phone number of the professor was successful." << endl;
    }
    // Remove Student
    else if (key == REMOVE) {
        cout << "Type in the phone number of the student you want to remove from the university" << endl;
        string phone_number;
        cin >> phone_number;
        Student *student = this->find_student_by_phone_number(phone_number);
        if (student == STUDENT_DOES_NOT_EXIST) {
            cout << "There does not exist a student with such a phone number in the university." << endl;
            return;
        }
        this->remove_student(phone_number);
        cout << "Removal of Student was successful." << endl;
    }
}

// 03. Add - Edit - Remove Course
void Secretary::add_edit_remove_course(void) {
    cout << "Do you want to 1) add, 2) edit or 3) remove a course from the university?" << endl;
    cout << "Select the option you want by pressing one of the above keys: 1,2,3." << endl;
    int key = get_user_input(1,3);
    if (key == ADD) {
        Course new_course;
        cin >> new_course;
        this->insert_course(&new_course);
    }
    else if (key == EDIT) {
        cout << "Type in the name of the course you want to edit. Instead of spaces " " you have to use dashes '-'." << endl;
        string course_name;
        cin >> course_name;
        Course *course = this->find_course(course_name);
        if (course == COURSE_DOES_NOT_EXIST) {
            cout << "There does not exist a course with such name in the university." << endl;
            return;
        }
        cout << "You can edit a course by entering the ECTs it attributes to a student when they pass the course." << endl;
        cout << "The ECTs a course can attribute can be a number between 2-8. Please type in the number:" << endl;
        int new_ECTs = get_user_input(2,8);
        int old_ECTs = course->course_get_ECTS();
        Course new_course = *course;
        new_course.course_set_ECTs(new_ECTs);
        this->insert_course(&new_course);
        this->remove_course(course_name);
        cout << "Changing the ECTs of Course '" << course->course_get_name()
             << "' from " << old_ECTs << " to " << new_ECTs << " was successful." << endl;
    }
    else if (key == REMOVE) {
        cout << "Type in the name of the course you want to remove. Instead of spaces " " you have to use dashes '-'." << endl;
        string course_name;
        cin >> course_name;
        Course *course = this->find_course(course_name);
        if (course == COURSE_DOES_NOT_EXIST) {
            cout << "There does not exist a course with such name in the university." << endl;
            return;
        }
        bool is_mandatory = course->course_is_mandatory();     
        if (is_mandatory) 
            cout << "Removal of a mandatory course is impossible." << endl;
        else {
            this->remove_course(course_name);
            cout << "Removal of Course was successful." << endl;
        } 
        
    }
    else return;
}

// 04. Set a professor to a course
void Secretary::course_set_professor(void) {
    cout << "Type in the name of the course you want to assign to a professor. Instead of spaces ' ' you have to use dashes '-'." << endl;
    string course_name;
    cin >> course_name;
    Course *course = this->find_course(course_name);
    if (course == COURSE_DOES_NOT_EXIST) {
        cout << "There does not exist a course with such name in the university." << endl;
        return;   
    }
    cout << "Type in the phone number of the professor you want to assign to a course." << endl;
    string phone_number;
    cin >> phone_number;
    Professor *professor = this->find_professor(phone_number);
    if (professor == PROFESSOR_DOES_NOT_EXIST) {
        cout << "There does not exist a professor with such phone number in the university." << endl;
        return;
    }
    professor->professor_set_course(course);
    cout << "Course '" << course_name << "' assigned to professor '" << professor->get_name() << "'." << endl; 
}

// 05. Join a course (for students).
void Secretary::student_join_course(void) {
    cout << "Type in the phone number of the student you want to join to a course." << endl;
    string phone_number;
    cin >> phone_number;
    Student *student = this->find_student_by_phone_number(phone_number);
    if (student == STUDENT_DOES_NOT_EXIST) {
        cout << "There does not exist a student with such phone number in the university." << endl;
        return;
    }
    cout << "Type in the name of the course you want the student to join. Instead of spaces " " you have to use dashes '-'." << endl;
    string course_name;
    cin >> course_name;
    Course *course = this->find_course(course_name);
    if (course == COURSE_DOES_NOT_EXIST) {
        cout << "There does not exist a course with such name in the university." << endl;
        return;
    }
    if (student->student_join_course(course))
        cout << "Student has successfully joined course." << endl;
    return;
}

// 06. Print and save the students that passed a course.
void Secretary::print_save_students_passed_course(void) {
    cout << "Type in the name of the course you want to see what students have passed." << endl;
    string course_name;
    cin >> course_name;
    Course *course = this->find_course(course_name);
    if (course == COURSE_DOES_NOT_EXIST) {
        cout << "There does not exist a course with such name in the university." << endl;
        return;
    }
    cout << "The students who are taking this course are the following:" << endl;
    Student **students_array = this->find_students_by_course(course_name);
    int array_size = 0;
    for (int i=0; i<INT_MAX; i++) {
        if (students_array[i] != nullptr) 
            array_size++;
        else 
            break;
    }
    for (int i=0; i<array_size; i++) {
        cout << *students_array[i] << endl;
    }
    uint count_of_students_that_passed = 0;
    cout << "The students that passed the course in the last semester are the following:" << endl;
    for (int i=0; i<array_size; i++) {
        if (students_array[i]->student_has_passed_course(course_name)) {
            cout << *students_array[i] << endl;
            count_of_students_that_passed++;
        }
    }
    if (count_of_students_that_passed == 0) {
        cout << "There are no students that have passed the said course in the last semester." << endl;
    }
}

// 07. Print the stats of current semester (for professors).
void Secretary::professor_print_stats(void) {
    cout << "Type in the phone number of the professor you want to see the statistics of:" << endl;
    string phone_number;
    cin >> phone_number;
    Professor *professor = this->find_professor(phone_number);
    if (professor == PROFESSOR_DOES_NOT_EXIST) {
        cout << "There does not exist a professor with such phone number in the university." << endl;
        return;
    }
    professor->professor_print_courses();
    cout << "Type in the name of the course in which you want to view the statistics of the professor." << endl;
    string course_name;
    cin >> course_name;
    Course *course = professor->professor_find_course(course_name);
    if (course == COURSE_DOES_NOT_EXIST) {
        cout << "Professor does not teach this course." << endl;
        return;
    }
    uint count = 0;
    map<string, Student*>::const_iterator map_iterator;
    for (map_iterator = students.begin(); map_iterator != students.end(); map_iterator++) {
        Student *student = map_iterator->second->student_has_joined_course(course_name);
        if (student == STUDENT_DOES_NOT_EXIST)
            continue;
        if (count == 0)
            cout << "Here is the list of all students that are taking this course followed by their grade:" << endl;
        student->student_print_course_and_grade(course_name);
        count = -1;
    } 
}

// 08. Print the stats of current and all semesters (for students).
void Secretary::student_print_stats(void) {
    cout << "Type in the phone number of the student you want to view the statistics of:" << endl;
    string phone_number;
    cin >> phone_number;
    Student *student = this->find_student_by_phone_number(phone_number);
    if (student == STUDENT_DOES_NOT_EXIST) {
        cout << "There does not exist a student with such phone number in the university." << endl;
        return;
    }
    student->student_print_semester_stats();
    student->student_print_all_stats();
}

// 09. Print and save the students that can graduate from the university.
void Secretary::print_students_that_can_graduate(void) {
    map<string, Student*>::const_iterator map_iterator;
    uint count_of_students_that_can_graduate = 0;
    for (map_iterator = students.begin(); map_iterator != students.end(); map_iterator++) {
        Student *potential_student = map_iterator->second;
        if (potential_student->student_can_graduate() && count_of_students_that_can_graduate == 0) {
            cout << "The students that have completed their studies and can graduate from the University are the following:" << endl;
            cout << *potential_student;
            count_of_students_that_can_graduate++;
        }
        else if (potential_student->student_can_graduate() && count_of_students_that_can_graduate > 0) {
            cout << *potential_student;
        }
    }
    if (count_of_students_that_can_graduate == 0) 
        cout << "As of now there does not exist a student that can graduate from the university." << endl;
}

// 10. Set a grade to course for a specific student (for professors).
void Secretary::professor_set_grade_to_course(void) {
    cout << "Type in the phone number of the professor you want to assign a grade to a course for a student." << endl;
    string phone_number;
    cin >> phone_number;
    Professor *professor = this->find_professor(phone_number);
    if (professor == PROFESSOR_DOES_NOT_EXIST) {
        cout << "There does not exist a professor with such a phone number in the university." << endl;
        return;
    }
    professor->professor_print_courses();
    cout << "Type in the name of the course you want the professor to a assign a grade to a student." << endl;
    string course_name;
    cin >> course_name;
    Course *course = professor->professor_find_course(course_name);
    if (course == COURSE_DOES_NOT_EXIST) {
        cout << "Professor does not teach this course." << endl;
        return;
    }
    cout << "The students who are taking this course are the following:" << endl;
    Student **students_array = this->find_students_by_course(course_name);
    int array_size = 0;
    for (int i=0; i<INT_MAX; i++) {
        if (students_array[i] != nullptr) 
            array_size++;
        else 
            break;
    }
    for (int i=0; i<array_size; i++) {
        cout << *students_array[i] << endl;
    }
    // ADD CHECK
    cout << "Select a student by entering their phone number:" << endl;
    string student_phone_number;
    cin >> student_phone_number;
    for (int i=0; i<array_size; i++) {
        if (students_array[i]->get_phone_number() == student_phone_number) {
            cout << "Enter the grade you want to assign to the student." << endl;
            uint grade;
            cin >> grade;
            students_array[i]->assign_grade_to_course(course_name, grade);
            cout << "Assigned the grade '" << grade << "' to student '" << students_array[i]->get_name() << "'." << endl;
        }
        else {
            cout << "There does not exist a student with such phone number that is taking the specific course." << endl;
        }
    }

}

//////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// COMPLIMENTARY HELPER FUNCTIONS ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////

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
    map<string, Professor*>::iterator it;
    it = professors.find(phone_number);
    if (it == professors.end()) 
        return false;
    delete it->second;
    return true;    
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

//////////////////////////////////////////////////////////////////////////////////////////////////////
////////////// ESSENTIAL CLASS FUNCTIONS (CONSTRUCTORS, OPERATION OVERLOADING ETC.) //////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////

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

Secretary::Secretary() {}

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
    map<string, Professor*>::iterator it;
    for (it = professors.begin(); it != professors.end(); it++) {
        if (it->second != NULL)
            delete it->second;
    }
    map<string, Student*>::iterator it_2;
    for (it_2 = students.begin(); it_2 != students.end(); it_2++) {
        if (it_2->second != NULL)
            delete it_2->second;
    }
    map<string, Course*>::iterator it_3;
    for (it_3 = courses.begin(); it_3 != courses.end(); it_3++) {
        if (it_3->second != NULL)
            delete it_3->second;
    }
}