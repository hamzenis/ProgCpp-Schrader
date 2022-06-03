// StudentCourseExam1.cpp : program with student, course, exams classes
//

#include <iostream>
#include <iomanip>
#include <vector>
#include "records.h"

using namespace std;

//  converts the grades to strings in german grade notation
string convertToGrade(float inGrade){
    string outGrade;
    if(inGrade >= 1 &&  inGrade < 1.2)   outGrade = "1+";
    if(inGrade >= 1.2 &&  inGrade < 1.6) outGrade = "1";
    if(inGrade >= 1.6 &&  inGrade < 1.9) outGrade = "1-";
    if(inGrade >= 1.9 &&  inGrade < 2.2) outGrade = "2+";
    if(inGrade >= 2.2 &&  inGrade < 2.6) outGrade = "2";
    if(inGrade >= 2.6 &&  inGrade < 2.9) outGrade = "2-";
    if(inGrade >= 2.9 &&  inGrade < 3.2) outGrade = "3+";
    if(inGrade >= 3.2 &&  inGrade < 3.6) outGrade = "3";
    if(inGrade >= 3.6 &&  inGrade < 3.9) outGrade = "3-";
    if(inGrade >= 3.9 &&  inGrade < 4.2) outGrade = "4+";
    if(inGrade >= 4.2 &&  inGrade < 4.6) outGrade = "4";
    if(inGrade >= 4.6 &&  inGrade < 4.9) outGrade = "4-";
    if(inGrade >= 4.9 &&  inGrade < 5.2) outGrade = "5+";
    if(inGrade >= 5.2 &&  inGrade < 5.6) outGrade = "5";
    if(inGrade >= 5.6 &&  inGrade < 5.9) outGrade = "5-";
    if(inGrade >= 5.9 &&  inGrade <= 6)  outGrade = "6";
    return outGrade;
}
//  the last print
void printEnd(float GPA, string studentShortName){
        cout    << "The GPA for " 
            << studentShortName
            << " is " 
            << convertToGrade(GPA) 
            << " Decimal: " 
            << setprecision(3) << GPA << endl;
}

//  initialize vectors
vector<Student> students = { Student(1,"George", "Burdell"),
                            Student(2,"Nancy", "Rhodes") };

vector<Course> courses = {  Course(1,"Algebra",5),
                            Course(2,"Physics",4),
                            Course(3,"English",3),
                            Course(4,"Economics",4) };

vector<Grade> grades = { Grade(1,1,2),
                        Grade(1,2,1),
                        Grade(1,3,3),
                        Grade(2,1,1),
                        Grade(2,2,2),
                        Grade(2,4,2) };

//  global variables
float GPA = 0.0f;
int id;

int main() {
    string studentName;      // long name of student
    string studentShortName; // short name of student

    //  select a student
    cout << "Enter a student ID: ";
    cin >> id;

    //  find name of student
    int i = 0;
    while (i < students.size() && students[i].getID() != id)
        i++;

    if (i == students.size()) {
        cout << "Student not found!" << endl;
        exit(1);
    }
    studentName = students[i].getName();
    studentShortName = students[i].getShortName();


    cout << "Results for: " << studentName << endl;

    //  calculation and printing
    float points = 0.0f;
    float credits = 0.0f;
    for (Grade& grd : grades)
        if (grd.getStudentID() == id) {

            //  calculate total credits and points
            int j = 0;
            while (j < courses.size() && courses[j].getID() != grd.getCourseID())
                j++;
            credits += courses[j].getCredits();
            points += grd.getGrade() * courses[j].getCredits();

            //  prints the individual grades
            cout << studentShortName << ": "
                << courses[j].getName() << " - "
                << courses[j].getCredits() << " - "
                << grd.getGrade() << " - "
                << convertToGrade(grd.getGrade()) << endl;
        }
    GPA = points / credits;

    printEnd(GPA, studentShortName);

    return (0);
}