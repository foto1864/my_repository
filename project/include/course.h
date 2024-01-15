#pragma once
#include "general.h"

class Course {
    private:
        string course_name;
        bool is_mandatory;
        uint semester;
        uint ECTs;
        uint grade;
    public:
        static int count;
        // Accessor functions
        string course_get_name(void);
        bool course_is_mandatory(void);
        uint course_get_semester(void);
        uint course_get_ECTS(void);
        uint course_get_grade(void);
        // Mutator functions
        void course_move_semester(uint);
        void course_set_grade(uint);
        void course_set_name(string name);
        void course_set_semester(uint sem);
        void course_set_ECTs(uint points);
        void course_set_is_mandatory(bool mand);
        // Operator Overloading
        friend ostream &operator<<(ostream &, Course&); 
        friend istream &operator>>(istream &, Course&);
        Course(); 
        Course(string, uint, bool, uint);
        ~Course();
};