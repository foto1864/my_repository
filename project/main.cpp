// File: project_section_a.cpp
#include "include/general.h"
#include "include/course.h"
#include "include/person.h"
#include "include/professor.h"
#include "include/secretary.h"
#include "include/student.h"
#include "include/utilities.h"

void call_intended_function(Secretary&, int);
void student_join_course(Secretary&);
void course_set_professor(Secretary&);
void professor_set_grade_to_course(Secretary&);
void print_save_students_passed_course(Secretary&);

int main(void) {
    Secretary university;
    load_database(university);
    show_menu();
    int key = get_user_input(1,11);
    while (key != EXIT_MENU) {
        call_intended_function(university, key);
        show_menu();
        key = get_user_input(1,11);
    }
    cout << "Thank you for using our university services!" << endl;
    return 0;
}

void course_set_professor(Secretary &uni) {
    cout << "Type in the name of the course you want to assign to a professor. Instead of spaces ' ' you have to use dashes '-'." << endl;
    string course_name;
    cin >> course_name;
    Course *course = uni.find_course(course_name);
    if (course == COURSE_DOES_NOT_EXIST) {
        cout << "There does not exist a course with such name in the university." << endl;
        return;   
    }
    cout << "Type in the phone number of the professor you want to assign to a course." << endl;
    string phone_number;
    cin >> phone_number;
    Professor *professor = uni.find_professor(phone_number);
    if (professor == PROFESSOR_DOES_NOT_EXIST) {
        cout << "There does not exist a professor with such phone number in the university." << endl;
        return;
    }
    professor->professor_set_course(course);
    cout << "Course '" << course_name << "' assigned to professor '" << professor->get_name() << "'." << endl; 
}

void student_join_course(Secretary &uni) {
    cout << "Type in the phone number of the student you want to join to a course." << endl;
    string phone_number;
    cin >> phone_number;
    Student *student = uni.find_student_by_phone_number(phone_number);
    if (student == STUDENT_DOES_NOT_EXIST) {
        cout << "There does not exist a student with such phone number in the university." << endl;
        return;
    }
    cout << "Type in the name of the course you want the student to join. Instead of spaces " " you have to use dashes '-'." << endl;
    string course_name;
    cin >> course_name;
    Course *course = uni.find_course(course_name);
    if (course == COURSE_DOES_NOT_EXIST) {
        cout << "There does not exist a course with such name in the university." << endl;
        return;
    }
    if (student->student_join_course(course))
        cout << "Student has successfully joined course." << endl;
    return;
}

void professor_set_grade_to_course(Secretary &uni) {
    cout << "Type in the phone number of the professor you want to assign a grade to a course for a student." << endl;
    string phone_number;
    cin >> phone_number;
    Professor *professor = uni.find_professor(phone_number);
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
    Student **students_array = uni.find_students_by_course(course_name);
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

void print_save_students_passed_course(Secretary &uni) {
    cout << "Type in the name of the course you want to see what students have passed." << endl;
    string course_name;
    cin >> course_name;
    Course *course = uni.find_course(course_name);
    if (course == COURSE_DOES_NOT_EXIST) {
        cout << "There does not exist a course with such name in the university." << endl;
        return;
    }
    cout << "The students who are taking this course are the following:" << endl;
    Student **students_array = uni.find_students_by_course(course_name);
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

void call_intended_function(Secretary &uni, int key) {
    // Call a function depending on the user's input
    switch (key) {
        case ADD_EDIT_REMOVE_PROFESSOR:
            uni.add_edit_remove_professor();
            break; 
        case ADD_EDIT_REMOVE_STUDENT:
            uni.add_edit_remove_student();
            break;
        case ADD_EDIT_REMOVE_COURSE:
            uni.add_edit_remove_course();
            break;
        case COURSE_SET_PROFESSOR:
            course_set_professor(uni);
            break;
        case STUDENT_JOIN_COURSE:
            student_join_course(uni);
            break;
        case PRINT_SAVE_STUDENTS_PASSED_COURSE:
            print_save_students_passed_course(uni);
            break;
        case PROFESSOR_PRINT_STATS:
            uni.professor_print_stats();
            break;
        case STUDENT_PRINT_STATS:
            uni.student_print_stats();
            break;
        case PRINT_STUDENTS_THAT_CAN_GRADUATE:
            uni.print_students_that_can_graduate();
            break;
        case PROFESSOR_SET_GRADE_TO_COURSE:
            professor_set_grade_to_course(uni);
            break;
        default:
            break;
    }
}