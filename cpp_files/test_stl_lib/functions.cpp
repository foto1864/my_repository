#include "functions.h"

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

int Student::get_academic_ID(void) {
    return academic_ID;
}
Student::Student() {
    cout << "Student Created" << endl;
}
Student::Student(string n, int a, int id) : Person(n,a) , academic_ID(id) {
    cout << "Student Created" << endl;
}