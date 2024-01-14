// File: project_section_a.cpp
#include "include/general.h"
#include "include/class_course.h"
#include "include/class_person.h"
#include "include/class_professor.h"
#include "include/class_secretary.h"
#include "include/class_student.h"

void show_menu(void);
int get_user_input(int, int);
void call_intended_function(int);
void load_database(Secretary&);
void load_students(Secretary&);
void load_professors(Secretary&);
void load_courses(void);

int main(void) {
    Secretary university;
    load_database(university);
    show_menu();
    int key = get_user_input(1,9);
    call_intended_function(key);
    cout << university;
    return 0;
}

void load_database(Secretary &sec) {
    load_students(sec);
    load_professors(sec);
    load_courses();
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

void load_courses(void) {
    ifstream courses_file("database/courses.txt");
    string line;
    while (getline(courses_file, line)) {
        istringstream iss(line);
        string course_name;
        uint semester;
        string mandatory;
        bool is_mandatory;
        uint ECTs;
        getline(iss, course_name, '-');
        iss >> semester;
        iss.ignore(); 
        getline(iss, mandatory, '-');
        iss >> ECTs;
        if (mandatory == "Mandatory")
            is_mandatory = true;
        else 
            is_mandatory = false;
        Course course(course_name, semester, is_mandatory, ECTs);
    }
    courses_file.close();
}

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

int get_user_input(int from, int to) {
    
    // Get input from the user
    int count = 0;
    int pressed_key;
    cin >> pressed_key;
    while ((pressed_key > to) || (pressed_key < from)) {
        count++;  
        if (count < 5) 
            cout << "Invalid key entered. You can only select an option from 1-9." << endl;   
        else if (count >= 5) {
            pressed_key = 10;
            break;
        }
        cin >> pressed_key;
    }
    return pressed_key;
}

void call_intended_function(int key) {
    
    // Call a function depending on the user's input
    switch (key) {
        case 1:
            break; 
        case 2:
            break;
        case 3:
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
        case 10:
            cout << "Too many failed attempts. Please try again later." << endl;
            break;
    }

}