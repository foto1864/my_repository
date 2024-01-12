#include "include/class_student.h"
#include "include/class_person.h"

int Student::student_count = 0;

uint Student::get_years_joined(void) {
        return year_joined_university;
}
void Student::set_years_joined(uint years) {
        year_joined_university = years;
}
Student::Student() { student_count++; }
Student::Student(string n,uint id) : Person(n, id) { student_count++; }
Student::Student(string n, string email, string number, uint year, uint id) : Person(n,email,number,year,id) { student_count++; }
Student::Student(string n, string email, string number, uint year, uint id, uint years_joined) 
        :Person(n,email,number,year,id), year_joined_university(years_joined) { student_count++; }
Student::~Student() { student_count--; }