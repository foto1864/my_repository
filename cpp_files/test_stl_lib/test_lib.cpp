#include <iostream>
#include <cstdlib>
#include <string>
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

string Person::get_name(void) {
    return name;
}
int Person::get_age(void) {
    return age;
}
Person::Person() {
    cout << "Person created" << endl;
}
Person::Person(string n, int a) : name(n), age(a) {
    cout << "Person created" << endl;
} 

class Student : public Person {
    private: 
        int academic_ID;
    public:
        int get_academic_ID(void);
        Student();
        Student(string n, int a, int id);
};

int Student::get_academic_ID(void) {
    return academic_ID;
}
Student::Student() {
    cout << "Student Created" << endl;
}
Student::Student(string n, int a, int id) : Person(n,a) , academic_ID(id) {
    cout << "Student Created" << endl;
}



int main(void) {

    Student student_a("Rodion Raskolnikov", 58, 207);
    cout << "Student's name is " << student_a.get_name() << endl;

    return 0;
}