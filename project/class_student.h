#pragma once
#include "general.h"
#include "class_person.h"

class Student : public Person {
    private:
        uint year_joined_university;
    public:
        static int student_count;
        Student();
        Student(string, uint);
        Student(string, string, string, uint, uint);
        Student(string, string, string, uint, uint, uint);
        ~Student();
};