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
        void print_students_that_can_graduate(void);
        void student_print_stats(void);
        void professor_print_stats(void);
        void add_edit_remove_course(void);
        void add_edit_remove_professor(void);
        void add_edit_remove_student(void);
        void student_join_course(void);
        void professor_set_grade_to_course(void);
        void course_set_professor(void);
        void print_save_students_passed_course(void);
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