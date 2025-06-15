#include "include/course.h"

int Course::count = 0;

string Course::course_get_name(void) {
    return course_name;
}
bool Course::course_is_mandatory(void) {
    return is_mandatory;
}
uint Course::course_get_semester(void) {
    return semester;
}
uint Course::course_get_ECTS(void) {
    return ECTs;
}
uint Course::course_get_grade(void) {
    return grade;
}
uint Course::course_get_id(void) {
    return course_id;
}
void Course::course_move_semester(uint new_semester) {
    if (new_semester > semester) {
        semester = new_semester;
    }
    else {
        cout << "You can't move a course to a previous semester than the one it's already on." << endl;
    }
    return;
}
void Course::course_set_grade(uint score) {
    grade = score;
}
void Course::course_set_name(string name) {
    course_name = name;
}
void Course::course_set_semester(uint sem) {
    semester = sem;
}
void Course::course_set_ECTs(uint points) {
    ECTs = points;
}
void Course::course_set_is_mandatory(bool mand) {
    is_mandatory = mand;
}
void Course::course_set_id(uint id) {
    course_id = id;
}

istream &operator>>(istream &str, Course &course) {
    cout << "Enter the Course's characteristics in the following order:" << endl;
    cout << "Course id, course name, semester, ECTs, M if course is mandatory or O if course is optional." << endl;
    bool is_mandatory;
    string is_mandatory_string;
    str >> course.course_id;
    str >> course.course_name;
    str >> course.semester;
    str >> course.ECTs;
    str >> is_mandatory_string;
    if (is_mandatory_string == "M") 
        is_mandatory = true;
    else if (is_mandatory_string == "O")
        is_mandatory = false;
    else {
        cout << "Invalid character entered. Please try again later." << endl;
        exit(1);
    }
    course.course_set_is_mandatory(is_mandatory);
    return str;
}

ostream &operator<<(ostream &str, Course &course) {
    str << course.course_name << " ";
    str << course.semester << " ";
    if (course.is_mandatory == true)
        str << "Mandatory ";
    else 
        str << "Optional ";
    str << course.ECTs;
    return str;
}

Course::Course() {
    count++;
}

Course::Course(uint id, string name, uint sem, bool mand, uint points) : course_name(name), ECTs(points) {
    count++;
    course_id = id;
    is_mandatory = mand;
    semester = sem;
}

Course::~Course() {
    count--;
}