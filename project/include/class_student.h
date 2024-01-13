#pragma once
#include "general.h"

class Student : public Person {
    private:
        uint year_joined_university;
        vector<Course> courses;
    public:
        static int student_count;
        uint get_years_joined(void);
        void set_years_joined(uint);
        Student();
        Student(string, uint);
        Student(string, string, string, uint, uint);
        Student(string, string, string, uint, uint, uint);
        ~Student();
};