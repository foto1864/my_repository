#pragma once
#include "general.h"

class Person {
    private:
        string name;
        string email_address;
        string phone_number;
        uint birth_year;
        uint academic_ID;
    public:
        static int count;
        // Mutator Functions
        void set_name(string);
        void set_email_address(string);
        void set_phone_number(string);
        void set_birth_year(uint);
        void set_academic_ID(uint);
        // Accessor Functions
        string get_name(void) const;
        string get_email_address(void) const;
        string get_phone_number(void) const;
        uint get_birth_year(void) const;
        uint get_academic_ID(void) const;
        // Operator Overloading
        friend ostream &operator<<(ostream &, Person &);
        friend istream &operator>>(istream &, Person &);
        // Constructors And Destructor
        Person();
        Person(string, uint);
        Person(string, string, string, uint, uint);
        ~Person();
};