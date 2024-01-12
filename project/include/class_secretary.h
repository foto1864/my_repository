#pragma once
#include "general.h"
#include "class_person.h"

class Secretary {
    private:
        map<string, Student*> students;
        map<string, Professor*> professors;
    public:
        void insert_student(Student*);
        void insert_professor(Professor*);
        bool find(string);
        uint size(void);
        friend ostream &operator<<(ostream &, const Secretary&);
        friend istream &operator>>(istream &, Secretary&);
        Secretary operator=(const Secretary&);
        Secretary operator+(const Person&);
        Secretary();
        Secretary(const Secretary&);
        ~Secretary();
};