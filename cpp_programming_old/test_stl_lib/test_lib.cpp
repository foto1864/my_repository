#include <iostream>
#include <cstdlib>
#include <string>
#include "functions.h"
using namespace std;

int main(void) {

    Student student_a("Rodion Raskolnikov", 58, 207);
    cout << "Student's name is " << student_a.get_name() << endl;

    return 0;
}