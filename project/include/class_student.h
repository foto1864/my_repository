#pragma once
#include "general.h"
#include "class_person.h"
#include "class_course.h"

class Student : public Person {
    private:
        uint years_joined_university;
        vector<Course> courses;
    public:
        static int student_count;
        uint get_years_joined(void);
        void set_years_joined(uint);
        void student_join_course(Course&);
        void student_print_courses(void);
        Student();
        Student(string, uint);
        Student(string, string, string, uint, uint);
        Student(string, string, string, uint, uint, uint);
        ~Student();
};