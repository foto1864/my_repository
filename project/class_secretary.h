#pragma once
#include "general.h"

class Secretary {
    private:
        map<string, Person*> university;
    public:
        void insert_person(Person*);
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