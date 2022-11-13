#include "student.h"
#include <iostream>
#include "person.h"

using namespace std;

int main() {
    Student s("Alice", "Bob", "3rd");
    cout    << s.getName() 
            << " is a student in " 
            << s.getSemester()
            << " semster." 
            << endl;


    Person p("Person", "Test");
    cout   << p.getName() 
            << " is a person." 
            << endl;


    return 0;
}