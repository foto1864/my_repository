// File: project_section_a.cpp
#include "include/general.h"
#include "include/course.h"
#include "include/person.h"
#include "include/professor.h"
#include "include/secretary.h"
#include "include/student.h"

void show_menu(void);
int get_user_input(int, int);
void call_intended_function(Secretary&, int);
void load_database(Secretary&);
void load_students(Secretary&);
void load_professors(Secretary&);
void load_courses(Secretary&);
void add_edit_remove_professor(Secretary&);
void add_edit_remove_student(Secretary&);
void add_edit_remove_course(Secretary&);

int main(void) {
    Secretary university;
    load_database(university);
    show_menu();
    int key = get_user_input(1,9);
    call_intended_function(university, key);
    cout << university;
    return 0;
}

void load_database(Secretary &sec) {
    load_students(sec);
    load_professors(sec);
    load_courses(sec);
    return;
}

void load_students(Secretary &sec) {
    ifstream students_file("database/students.txt");
    string line;
    while (getline(students_file, line)) {
        istringstream iss(line);
        string name;
        string email_address;
        string phone_number;
        uint birth_year;
        uint id;
        iss >> name >> id >> phone_number >> birth_year >> email_address;
        uint year_joined_university = CURRENT_YEAR - (id/100);
        Student student(name, email_address, phone_number, birth_year, id, year_joined_university);
        sec.insert_student(&student);
    }
    students_file.close();
}

void load_professors(Secretary &sec) {
    ifstream professors_file("database/professors.txt");
    string line;
    while (getline(professors_file, line)) {
        istringstream iss(line);
        string name;
        string email_address;
        string phone_number;
        uint birth_year;
        uint id;
        iss >> name >> id >> phone_number >> birth_year >> email_address;
        uint years_of_experience = CURRENT_YEAR - (id/100);
        Professor professor(name, email_address, phone_number, birth_year, id, years_of_experience);
        sec.insert_professor(&professor);
    }
    professors_file.close();
}

void load_courses(Secretary &sec) {
    ifstream courses_file("database/courses.txt");
    string line;
    while (getline(courses_file, line)) {
        
    }
    courses_file.close();
}

void show_menu(void) {
    // Show the menu of options to the User
    cout << endl << "Welcome to our University! You have the following options:" << endl << endl;
    cout << "1) Add - Edit - Remove Professor" << endl;
    cout << "2) Add - Edit - Remove Student" << endl;
    cout << "3) Add - Edit - Remove Course" << endl;
    cout << "4) Set the professor of a course" << endl;
    cout << "5) Register to a course (for students only)" << endl;
    cout << "6) Print a list of the students that passed a course in the current semester" << endl; 
    cout << "7) Print the statistics for all courses in the current semester (for Professors only)" << endl;
    cout << "8) Print your average score (for students only)" << endl;
    cout << "9) Print a list of all the students that are eligible to graduate from the University" << endl << endl;
    cout << "You can select one of the options 1-9 by pressing the corresponding key." << endl;
}

int get_user_input(int from, int to) {
    // Get input from the user
    int count = 0;
    int pressed_key;
    cin >> pressed_key;
    while ((pressed_key > to) || (pressed_key < from)) {
        count++;  
        if (count < 5) 
            cout << "Invalid number entered. You can only select an option from " << from << "-" << to << "." << endl;   
        else if (count >= 5) {
            cout << "Too many failed attempts. Please try again later." << endl;
            exit(1);
            break;
        }
        cin >> pressed_key;
    }
    return pressed_key;
}

void add_edit_remove_professor(Secretary &uni) {
    cout << "Do you want to 1) add, 2) edit or 3) remove a professor from the university?" << endl;
    cout << "Select the option you want by pressing one of the above keys, 1,2 or 3." << endl;
    int key = get_user_input(1,3);
    // Add Professor
    if (key == ADD) {
        Professor new_professor;
        cin >> new_professor;
        uni.insert_professor(&new_professor);
    }
    // Edit Professor
    else if (key == EDIT) {
        cout << "You can edit a professor by changing their phone_number." << endl;
        cout << "Type in the phone number of the professor you want to edit." << endl;
        string phone_number;
        cin >> phone_number;
        Professor *old_professor = uni.find_professor(phone_number);
        if (old_professor == PROFESSOR_DOES_NOT_EXIST) {
            cout << "There does not exist a professor with such a phone number in the university." << endl;
            exit(1);
        }
        else {
            cout << "Type in the new phone number of the professor." << endl;
            string new_phone_number;
            cin >> new_phone_number;
            Professor new_professor = *old_professor;
            new_professor.set_phone_number(new_phone_number);
            uni.insert_professor(&new_professor);
            uni.remove_professor(phone_number);
            cout << "The change of the phone number of the professor was successful." << endl;
        }

    }
    // Remove Professor
    else if (key == REMOVE) {
        cout << "Type in the phone number of the professor you want to remove from the university" << endl;
        string phone_number;
        cin >> phone_number;
        Professor *professor = uni.find_professor(phone_number);
        if (professor == PROFESSOR_DOES_NOT_EXIST) {
            cout << "There does not exist a professor with such a phone number in the university." << endl;
            exit(1);
        }
        else {
            uni.remove_professor(phone_number);
            cout << "Removal of Professor was successful." << endl;
        }
    }
    else return;
}


void add_edit_remove_student(Secretary &uni) {
    cout << "Do you want to 1) add, 2) edit or 3) remove a student from the university?" << endl;
    cout << "Select the option you want by pressing one of the above keys, 1,2 or 3." << endl;
    int key = get_user_input(1,3);
    // Add student
    if (key == ADD) {
        Student new_student;
        cin >> new_student;
        uni.insert_student(&new_student);
    }
    // Edit Student
    else if (key == EDIT) {
        cout << "You can edit a student by changing their phone_number." << endl;
        cout << "Type in the phone number of the student you want to edit." << endl;
        string phone_number;
        cin >> phone_number;
        Student *old_student = uni.find_student(phone_number);
        if (old_student == STUDENT_DOES_NOT_EXIST) {
            cout << "There does not exist a student with such a phone number in the university." << endl;
            exit(1);
        }
        else {
            cout << "Type in the new phone number of the student." << endl;
            string new_phone_number;
            cin >> new_phone_number;
            Student new_student = *old_student;
            new_student.set_phone_number(new_phone_number);
            uni.insert_student(&new_student);
            uni.remove_student(phone_number);
            cout << "The change of the phone number of the professor was successful." << endl;
        }
    }
    // Remove Student
    else if (key == REMOVE) {
        cout << "Type in the phone number of the student you want to remove from the university" << endl;
        string phone_number;
        cin >> phone_number;
        Student *student = uni.find_student(phone_number);
        if (student == STUDENT_DOES_NOT_EXIST) {
            cout << "There does not exist a student with such a phone number in the university." << endl;
            exit(1);
        }
        else {
            uni.remove_student(phone_number);
            cout << "Removal of Student was successful." << endl;
        }
    }
}

void add_edit_remove_course(Secretary &uni) {
    cout << "Do you want to 1) add, 2) edit or 3) remove a course from the university?" << endl;
    cout << "Select the option you want by pressing one of the above keys: 1,2,3." << endl;
    int key = get_user_input(1,3);
    if (key == ADD) {
        Course new_course;
        cin >> new_course;
        uni.insert_course(&new_course);
    }
    else if (key == EDIT) {
        cout << "Type in the name of the course you want to edit." << endl;
        string course_name;
        cin >> course_name;
        Course *course = uni.find_course(course_name);
        if (course == COURSE_DOES_NOT_EXIST) {
            cout << "There does not exist a course with such name in the university." << endl;
            exit(1);
        }
        else {
            cout << "You can edit a course by entering the ECTs it attributes to a student when they pass the course." << endl;
            cout << "The ECTs a course can attribute can be a number between 2-8. Please type in the number:" << endl;
            int new_ECTs = get_user_input(2,8);
            int old_ECTs = course->course_get_ECTS();
            Course new_course = *course;
            new_course.course_set_ECTs(new_ECTs);
            uni.insert_course(&new_course);
            uni.remove_course(course_name);
            cout << "Changing the ECTs of Course '" << course->course_get_name()
                 << "' from " << old_ECTs << " to " << new_ECTs << " was successful." << endl;
        }
    }
    else if (key == REMOVE) {
        cout << "Type in the name of the course you want to remove." << endl;
        string course_name;
        cin >> course_name;
        Course *course = uni.find_course(course_name);
        if (course == COURSE_DOES_NOT_EXIST) {
            cout << "There does not exist a course with such name in the university." << endl;
            exit(1);
        }
        else {
            bool is_mandatory = course->course_is_mandatory();     
            if (is_mandatory) 
                cout << "Removal of a mandatory course is impossible." << endl;
            else {
                uni.remove_course(course_name);
                cout << "Removal of Course was successful." << endl;
            } 
        }
    }
    else return;
}


void call_intended_function(Secretary &uni, int key) {
    // Call a function depending on the user's input
    switch (key) {
        case ADD_EDIT_REMOVE_PROFESSOR:
            add_edit_remove_professor(uni);
            break; 
        case ADD_EDIT_REMOVE_STUDENT:
            add_edit_remove_student(uni);
            break;
        case ADD_EDIT_REMOVE_COURSE:
            add_edit_remove_course(uni);
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        default:
            break;
    }
}