#pragma once
#include "general.h"

class Course {
    private:
        string course_name;
        bool mandatory;
        uint semester;
        uint ECTs;
    public:
        string course_get_name(void);
        bool course_is_mandatory(void);
        uint course_get_semester(void);
        uint course_get_ECTS(void);
        void course_move_semester(uint new_semester);
        Course(string, uint, bool, uint);
};