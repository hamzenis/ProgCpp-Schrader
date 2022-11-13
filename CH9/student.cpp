#include "student.h"

using namespace std;

Student::Student(string fname, string lname, string semester) : Person(fname, lname) {
    this->semester = semester;
}

string Student::getSemester() {
    return semester;
}

