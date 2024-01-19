// File: project_section_a.cpp
#include "include/general.h"
#include "include/course.h"
#include "include/person.h"
#include "include/professor.h"
#include "include/secretary.h"
#include "include/student.h"
#include "include/utilities.h"

void call_intended_function(Secretary&, int);

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
            uni.course_set_professor();
            break;
        case STUDENT_JOIN_COURSE:
            uni.student_join_course();
            break;
        case PRINT_SAVE_STUDENTS_PASSED_COURSE:
            uni.print_save_students_passed_course();
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
            uni.professor_set_grade_to_course();
            break;
        default:
            break;
    }
}