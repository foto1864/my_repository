#pragma once
#include "general.h"

class Course {
    private:
        string course_name;
        bool is_mandatory;
        uint course_id;
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
        uint course_get_id(void);
        // Mutator functions
        void course_move_semester(uint);
        void course_set_grade(uint);
        void course_set_name(string name);
        void course_set_semester(uint sem);
        void course_set_ECTs(uint points);
        void course_set_is_mandatory(bool mand);
        void course_set_id(uint id);
        // Operator Overloading
        friend ostream &operator<<(ostream &, Course&); 
        friend istream &operator>>(istream &, Course&);
        Course(); 
        Course(uint, string, uint, bool, uint);
        ~Course();
};