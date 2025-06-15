#pragma once
#include "general.h"
#include "person.h"
#include "course.h"

class Student : public Person {
    private:
        uint years_joined_university;
        map<string, Course*> student_courses;
    public:
        static int student_count;
        uint get_years_joined(void);
        void set_years_joined(uint);
        bool student_join_course(Course*);
        void student_print_courses(void);
        void assign_grade_to_course(string, uint);
        bool student_can_graduate(void);
        uint student_get_course_grade(string);
        bool student_has_passed_course(string);
        void student_print_semester_stats(void);
        void student_print_all_stats(void);
        void student_print_course_and_grade(string);
        Student* student_has_joined_course(string);
        Student();
        Student(string, uint);
        Student(string, string, string, uint, uint);
        Student(string, string, string, uint, uint, uint);
        ~Student();
};

