#include "general.h"

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