#include <iostream>
using namespace std;

class Person {
    private:
        string name;
        int age;
    public:
        string get_name(void);
        int get_age(void);
        Person();
        Person(string, int);
};

class Student : public Person {
    private: 
        int academic_ID;
    public:
        int get_academic_ID(void);
        Student();
        Student(string n, int a, int id);
};