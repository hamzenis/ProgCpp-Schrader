/*
 * File: StudentCourseExam1.cpp
 * Project: Objektorientierte Progammierung in C++ - Schrader
 * Created Date: 2022-06-03, 12:13:19 am
 * Author: Hamzenis Kryeziu
 * E-Mail: hamzenis.kryeziu@stud.fra-uas.de
 * -----
 * Last Modified: 2022-06-13, 11:25:33 am
 * Modified By: Hamzenis Kryeziu
 * -----
 * Copyright (c) 2022
 *
 * Free for use
 * -----
 * HISTORY:
 * Date              		By		Comments
 * ------------------		----	----------------------------------------------------------
 * 2022-06-03, 12:13:19 am	H.K.	-start-
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include "records.h"

using namespace std;

//  Start Classes
class StudentRecords {

private:
    vector<Student> students;
    vector<Course> courses;
    vector<Grade> grades;

public:
    StudentRecords(vector<Student> students, vector<Course> courses, vector<Grade> grades);
    vector<Student> getVecStudent();
    vector<Course> getVecCourse();
    vector<Grade> getVecGrade();
};

StudentRecords::StudentRecords(vector<Student> students, vector<Course> courses, vector<Grade> grades) {
    this->students = students;
    this->courses = courses;
    this->grades = grades;
}
vector<Student> StudentRecords::getVecStudent(){
    return students;
}
vector<Course> StudentRecords::getVecCourse(){
    return courses;
}
vector<Grade> StudentRecords::getVecGrade(){
    return grades;
}
//  End Classes


//  global variables
float GPA = 0.0f;
int id;

//  converts the grades to strings in german grade notation
string convertToGrade(float inGrade) {
    string outGrade;
    if (inGrade >= 1 && inGrade < 1.2)   outGrade = "1+";
    if (inGrade >= 1.2 && inGrade < 1.6) outGrade = "1";
    if (inGrade >= 1.6 && inGrade < 1.9) outGrade = "1-";
    if (inGrade >= 1.9 && inGrade < 2.2) outGrade = "2+";
    if (inGrade >= 2.2 && inGrade < 2.6) outGrade = "2";
    if (inGrade >= 2.6 && inGrade < 2.9) outGrade = "2-";
    if (inGrade >= 2.9 && inGrade < 3.2) outGrade = "3+";
    if (inGrade >= 3.2 && inGrade < 3.6) outGrade = "3";
    if (inGrade >= 3.6 && inGrade < 3.9) outGrade = "3-";
    if (inGrade >= 3.9 && inGrade < 4.2) outGrade = "4+";
    if (inGrade >= 4.2 && inGrade < 4.6) outGrade = "4";
    if (inGrade >= 4.6 && inGrade < 4.9) outGrade = "4-";
    if (inGrade >= 4.9 && inGrade < 5.2) outGrade = "5+";
    if (inGrade >= 5.2 && inGrade < 5.6) outGrade = "5";
    if (inGrade >= 5.6 && inGrade < 5.9) outGrade = "5-";
    if (inGrade >= 5.9 && inGrade <= 6)  outGrade = "6";
    return outGrade;
}
//  the last print
void printEnd(string studentShortName) {
    cout << "The GPA for "
        << studentShortName
        << " is "
        << convertToGrade(GPA)
        << " Decimal: "
        << setprecision(3) << GPA << endl;
}

//  prints the individual grades
void printIndividual(int j, string studentShortName, Grade grd) {
    cout << studentShortName << ": "
        << courses[j].getName() << " - "
        << courses[j].getCredits() << " - "
        << grd.getGrade() << " - "
        << convertToGrade(grd.getGrade()) << endl;
}

//  calculate and print the GPA
float calcprint(string studentShortName, string studentName, int id) {
    float ergebnis = 0.0f;
    float points = 0.0f;
    float credits = 0.0f;

    cout << "Results for: " << studentName << endl;
    for (Grade& grd : grades)
        if (grd.getStudentID() == id) {
            //  calculate total credits and points
            int j = 0;
            while (j < courses.size() && courses[j].getID() != grd.getCourseID())
                j++;
            credits += courses[j].getCredits();
            points += grd.getGrade() * courses[j].getCredits();

            printIndividual(j, studentShortName, grd);
        };
    ergebnis = points / credits;

    return ergebnis;
}

//  find name of student
int findStudent() {
    int i = 0;
    while (i < students.size() && students[i].getID() != id)
        i++;
    return i;
}

//  select a student
void selectStudent() {
    cout << "Enter a student ID: ";
    cin >> id;
}

//  checks if student exists
void notFoundCheck(int i) {
    if (i == students.size()) {
        cout << "Student not found!" << endl;
        exit(1);
    }
}

int main() {
    string studentName;
    string studentShortName;
    //  initialize vectors
    vector<Student> students = { Student(1,"George", "Burdell"),
                                Student(2,"Nancy", "Rhodes") };

    vector<Course> courses = { Course(1,"Algebra",5),
                                Course(2,"Physics",4),
                                Course(3,"English",3),
                                Course(4,"Economics",4) };

    vector<Grade> grades = { Grade(1,1,2),
                            Grade(1,2,1),
                            Grade(1,3,3),
                            Grade(2,1,1),
                            Grade(2,2,2),
                            Grade(2,4,2) };
    //  Objects
    StudentRecords example(students, courses, grades);

    selectStudent();
    int i = findStudent();
    notFoundCheck(i);

    studentName = example.getVecStudent();   //student[i].getName();
    studentShortName = students[i].getShortName();

    GPA = calcprint(studentShortName, studentName, id);
    printEnd(studentShortName);

    return (0);
}