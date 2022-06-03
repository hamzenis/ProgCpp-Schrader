// StudentCourseExam1.cpp : program with student, course, exams classes
//

#include <iostream>
#include <vector>
#include "records.h"

using namespace std;

// initialize vectors

vector<Student> students = { Student(1,"George", "Burdell"),
                            Student(2,"Nancy", "Rhodes") };

vector<Course> courses = {  Course(1,"Algebra",5),
                            Course(2,"Physics",4),
                            Course(3,"English",3),
                            Course(4,"Economics",4) };

vector<Grade> grades = { Grade(1,1,'B'),
                        Grade(1,2,'A'),
                        Grade(1,3,'C'),
                        Grade(2,1,'A'),
                        Grade(2,2,'A'),
                        Grade(2,4,'B') };

float GPA = 0.0f;
int id;

int main() {
    string studentName;      // long name of student
    string studentShortName; // short name of student

    // select a student
    cout << "Enter a student ID: ";
    cin >> id;

    // find name of student
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

    float points = 0.0f;
    float credits = 0.0f;

    for (Grade& grd : grades)
        if (grd.getStudentID() == id) {
            float num_grd;          // float for the numeric grade
            switch (grd.getGrade()) {
                case 'A': num_grd = 4.0f;
                    break;
                case 'B': num_grd = 3.0f;
                    break;
                case 'C': num_grd = 2.0f;
                    break;
                case 'D': num_grd = 1.0f;
                    break;
                default:  num_grd = 0.0f;
                    break;
            };
            // calculate total credits and points
            int j = 0;
            while (j < courses.size() && courses[j].getID() != grd.getCourseID())
                j++;
            credits += courses[j].getCredits();
            points += num_grd * courses[j].getCredits();

            cout << studentShortName << ": "
                << courses[j].getName() << " - "
                << courses[j].getCredits() << " - "
                << grd.getGrade() << " - "
                << num_grd << endl;

        }
    GPA = points / credits;

    cout << "The GPA for " << studentShortName << " is " << GPA << endl;
    return (0);
}