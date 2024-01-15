#pragma once
#include "general.h"
#include "person.h"
#include "course.h"

class Professor : public Person {
    private:
        uint years_of_experience;
        map<string, Course*> professor_courses;
    public:
        static int professor_count;
        uint get_years_experience(void);
        void set_years_of_experience(uint);
        void professor_set_course(Course*);
        void professor_print_courses(void);
        Course *professor_find_course(string);
        Professor();
        Professor(string, uint);
        Professor(string, string, string, uint, uint);
        Professor(string, string, string, uint, uint, uint);
        ~Professor();
};