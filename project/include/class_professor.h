#pragma once
#include "general.h"

class Professor : public Person {
    private:
        uint years_of_experience;
    public:
        static int professor_count;
        uint get_years_experience(void);
        void set_years_of_experience(uint);
        Professor();
        Professor(string, uint);
        Professor(string, string, string, uint, uint);
        Professor(string, string, string, uint, uint, uint);
        ~Professor();
};