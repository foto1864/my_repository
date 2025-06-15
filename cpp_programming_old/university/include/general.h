#pragma once
#include <iostream>
#include <map>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>
#include <limits.h>
#define ADD 1
#define EDIT 2
#define REMOVE 3
#define ADD_EDIT_REMOVE_PROFESSOR 1
#define ADD_EDIT_REMOVE_STUDENT 2
#define ADD_EDIT_REMOVE_COURSE 3
#define COURSE_SET_PROFESSOR 4
#define STUDENT_JOIN_COURSE 5
#define PRINT_SAVE_STUDENTS_PASSED_COURSE 6
#define PROFESSOR_PRINT_STATS 7
#define STUDENT_PRINT_STATS 8
#define PRINT_STUDENTS_THAT_CAN_GRADUATE 9
#define PROFESSOR_SET_GRADE_TO_COURSE 10
#define EXIT_MENU 11
#define PASSING_MARK 5
#define TOTAL_MANDATORY_COURSES 8
#define GRADUATION_MINIMUM_SCORE 98
#define STUDENT_DOES_NOT_EXIST nullptr
#define PROFESSOR_DOES_NOT_EXIST nullptr
#define COURSE_DOES_NOT_EXIST nullptr
#define CURRENT_YEAR 2022
using namespace std;