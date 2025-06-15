#include "include/utilities.h"

void load_database(Secretary &sec) {
    load_students(sec);
    load_professors(sec);
    load_courses(sec);
    return;
}

void read_file(const string &file_path, Secretary &sec) {

    ifstream file(file_path);
    string line;
    while(getline(file, line)) {
        istringstream iss(line);
        string name, email_address, phone_number;
        uint birth_year, id;
        iss >> name >> email_address >> phone_number >> birth_year >> id;
        uint years_joined = CURRENT_YEAR - (id/100);
        Student student(name, email_address, phone_number, birth_year, id, years_joined);
        sec.insert_student(&student);
    }
    file.close();
}

void load_students(Secretary &sec) {
    ifstream students_file("database/students.txt");
    if (!students_file.is_open()) {
        cout << "Error occured in opening 'students.txt' file." << endl;
        exit(1);
    }
    string line;
    while (getline(students_file, line)) {
        istringstream iss(line);
        string name, email_address, phone_number;
        uint birth_year, id;
        iss >> name >> id >> phone_number >> birth_year >> email_address;
        uint year_joined_university = CURRENT_YEAR - (id/100);
        Student student(name, email_address, phone_number, birth_year, id, year_joined_university);
        sec.insert_student(&student);    
    }    
    students_file.close();
}

void load_professors(Secretary &sec) {
    ifstream professors_file("database/professors.txt");
    if (!professors_file.is_open()) {
        cout << "Error occured in opening 'professors.txt' file." << endl;
        exit(1);
    }
    string line;
    while (getline(professors_file, line)) {
        istringstream iss(line);
        string name, email_address, phone_number;
        uint birth_year, id;
        iss >> name >> id >> phone_number >> birth_year >> email_address;
        uint years_of_experience = CURRENT_YEAR - (id/100);
        Professor professor(name, email_address, phone_number, birth_year, id, years_of_experience);
        sec.insert_professor(&professor);
    }
    professors_file.close();
}

void load_courses(Secretary &sec) {
    ifstream courses_file("database/courses.txt");
    if (!courses_file.is_open()) {
        cout << "Error occured in opening 'courses.txt' file." << endl;
        exit(1);
    }
    string line;
    while (getline(courses_file, line)) {
        istringstream iss(line);
        uint course_id, semester;
        string course_name, mandatory;
        bool is_mandatory;
        uint ECTs;
        iss >> course_id >> course_name >> semester >> mandatory >> ECTs;

        if (mandatory == "Mandatory")
            is_mandatory = true;
        else 
            is_mandatory = false;

        Course course(course_id, course_name, semester, is_mandatory, ECTs);
        sec.insert_course(&course);
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
    cout << "9) Print a list of all the students that are eligible to graduate from the University" << endl;
    cout << "10) Assign a grade to a course for a specific student (for professors only)." << endl;
    cout << "11) EXIT MENU. " << endl << endl;
    cout << "You can select one of the options 1-11 by pressing the corresponding key." << endl;
}

int get_user_input(int from, int to) {
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

