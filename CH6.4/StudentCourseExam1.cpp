/*
 * File: StudentCourseExam1.cpp
 * Project: Objektorientierte Progammierung in C++ - Schrader
 * Created Date: 2022-06-03, 12:13:19 am
 * Author: Hamzenis Kryeziu
 * E-Mail: hamzenis.kryeziu@stud.fra-uas.de
 * -----
 * Last Modified: 2022-06-18, 7:20:56 pm
 * Modified By: Hamzenis Kryeziu
 * -----
 * Copyright (c) 2022
 *
 * Free for use
 * -----
 * HISTORY:
 * Date              		By		Comments
 * ------------------		----	----------------------------------------------------------
 * 2022-06-18, 7:06:17 pm	H.K.	v1
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
    //  Parameterized constructor 
    StudentRecords(vector<Student> students, vector<Course> courses, vector<Grade> grades);
    //  Default constructor
    StudentRecords();
    vector<Student> getVecStudent();
    vector<Course> getVecCourse();
    vector<Grade> getVecGrade();
    string getCoursesName(int i);
    int getCoursesCredit(int i);
    string getStudentsName(int i);
    string getStudentsShortName(int i);
    int getStudentsSize();
    int getStudentsID(int i);
    int getCoursesSize();
    int getCoursesID(int i);
    void pushStudent(int id, string firstname, string lastname);
    void pushGrade(int studentid, int  courseid, float grade);
    void pushCourse(int id, string name, unsigned char credits);
    void printCourses();
    void printGrades();
    void printStudents();
};

StudentRecords::StudentRecords(vector<Student> students, vector<Course> courses, vector<Grade> grades) {
    this->students = students;
    this->courses = courses;
    this->grades = grades;
}
StudentRecords::StudentRecords() {
}
vector<Student> StudentRecords::getVecStudent() {
    return students;
}
vector<Course> StudentRecords::getVecCourse() {
    return courses;
}
vector<Grade> StudentRecords::getVecGrade() {
    return grades;
}
string StudentRecords::getCoursesName(int i) {
    return courses[i].getName();
}
int StudentRecords::getCoursesCredit(int i) {
    return courses[i].getCredits();
}
string StudentRecords::getStudentsName(int i) {
    return students[i].getName();
}
string StudentRecords::getStudentsShortName(int i) {
    return students[i].getShortName();
}
int StudentRecords::getStudentsSize() {
    return students.size();
}
int StudentRecords::getStudentsID(int i) {
    return students[i].getID();
}
int StudentRecords::getCoursesSize() {
    return courses.size();
}
int StudentRecords::getCoursesID(int i) {
    return courses[i].getID();
}
void StudentRecords::pushStudent(int id, string firstname, string lastname) {
    Student a(id, firstname, lastname);
    students.push_back(a);
}
void StudentRecords::pushGrade(int studentid, int  courseid, float grd) {
    Grade a(studentid, courseid, grd);
    grades.push_back(a);
}
void StudentRecords::pushCourse(int id, string name, unsigned char credits) {
    Course a(id, name, credits);
    courses.push_back(a);
}
void StudentRecords::printCourses() {
    for (Course& crs : courses) {
        cout << crs.getID()
            << " " + crs.getName() + " Gewichtung: "
            << crs.getCredits()
            << endl;
    }
}
void StudentRecords::printGrades() {
    for (Grade& grd : grades) {
        cout << "Course ID: "
            << grd.getCourseID()
            << " Studenten ID: "
            << grd.getStudentID()
            << " Note: "
            << grd.getGrade()
            << endl;
    }
}
void StudentRecords::printStudents() {
    for(Student& stdt : students){
        cout << stdt.getID()
            << " " + stdt.getName()
            << endl;
    }
}
//  End Classes

/*----------Functions----------*/

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
void printEnd(int i, StudentRecords& stdR, float GPA) {
    cout << "The GPA for "
        << stdR.getStudentsShortName(i)
        << " is "
        << convertToGrade(GPA)
        << " Decimal: "
        << setprecision(3) << GPA << endl;
}

//  prints the individual grades
void printIndividual(int index, int& i, Grade& grd, StudentRecords& stdR) {
    cout << stdR.getStudentsShortName(index) << ": "
        << stdR.getCoursesName(i) << " - "
        << stdR.getCoursesCredit(i) << " - "
        << grd.getGrade() << " - "
        << convertToGrade(grd.getGrade()) << endl;
}

//  calculate and print the GPA
float calcprint(int id, StudentRecords& stdR, int& i) {
    float ergebnis = 0.0f;
    float points = 0.0f;
    float credits = 0.0f;

    cout << "Results for: " << stdR.getStudentsName(i) << endl;
    for (Grade& grd : stdR.getVecGrade())
        if (grd.getStudentID() == id) {
            //  calculate total credits and points
            int j = 0;
            while (j < stdR.getCoursesSize() && stdR.getCoursesID(j) != grd.getCourseID())
                j++;
            credits += stdR.getCoursesCredit(j);
            points += grd.getGrade() * stdR.getCoursesCredit(j);
            printIndividual(i, j, grd, stdR);
        };
    ergebnis = points / credits;

    return ergebnis;
}

//  find name of student
int findStudent(StudentRecords& stdR, int id) {
    int i = 0;
    while (i < stdR.getStudentsSize() && stdR.getStudentsID(i) != id)
        i++;
    return i;
}

//  select a student
int selectStudent() {
    int id;
    cout << "Enter a student ID: ";
    cin >> id;
    return id;
}

//  checks if student exists
void notFoundCheck(int i, StudentRecords& stdR) {
    if (i == stdR.getStudentsSize()) {
        cout << "Student not found!" << endl;
        exit(1);
    }
}

int main() {
    string studentName;
    string studentShortName;
    int id, i;
    float GPA = 0.0f;

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

    //  Methoden Test mit neuen Objekten
    example.pushStudent(4, "Hamzenis", "Kryeziu");
    example.pushGrade(4, 1, 1.3);
    example.pushGrade(4, 2, 1.5);
    example.pushGrade(4, 4, 3.0);
    example.pushGrade(4, 3, 2.3);

    //  Ausführung
    id = selectStudent();
    i = findStudent(example, id);
    notFoundCheck(i, example);

    GPA = calcprint(id, example, i);
    printEnd(i, example, GPA);

    //  Print Test
    example.printStudents();
    example.printCourses();
    example.printGrades();


    return (0);
}