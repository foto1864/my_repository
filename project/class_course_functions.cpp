#include "include/general.h"
#include "include/class_course.h"

string Course::course_get_name(void) {
    return course_name;
}
bool Course::course_is_mandatory(void) {
    return mandatory;
}
uint Course::course_get_semester(void) {
    return semester;
}
uint Course::course_get_ECTS(void) {
    return ECTs;
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
Course::Course(string name, uint sem, bool mand, uint points) : course_name(name), semester(sem), mandatory(mand), ECTs(points) {}