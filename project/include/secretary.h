#pragma once
#include "general.h"
#include "student.h"
#include "professor.h"

class Secretary {
    private:
        map<string, Student*> students;
        map<string, Professor*> professors;
        map<string, Course*> courses;
    public:
        void insert_student(Student*);
        void insert_professor(Professor*);
        void insert_course(Course*);
        bool remove_professor(string);
        bool remove_student(string);
        bool remove_course(string);
        Student* find_student_by_phone_number(string);
        Student** find_students_by_course(string);
        Professor* find_professor(string);
        Course* find_course(string);
        uint size(void);
        friend ostream &operator<<(ostream &, const Secretary&);
        friend istream &operator>>(istream &, Secretary&);
        Secretary operator=(const Secretary&);
        Secretary operator+(const Student&);
        Secretary operator+(const Professor&);
        Secretary();
        Secretary(const Secretary&);
        ~Secretary();
};