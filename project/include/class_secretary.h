#pragma once
#include "general.h"
#include "class_student.h"
#include "class_professor.h"

class Secretary {
    private:
        map<string, Student*> students;
        map<string, Professor*> professors;
    public:
        void insert_student(Student*);
        void insert_professor(Professor*);
        bool find_student(string);
        bool find_professor(string);
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