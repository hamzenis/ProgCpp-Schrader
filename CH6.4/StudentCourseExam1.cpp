/*
 * File: StudentCourseExam1.cpp
 * Project: Objektorientierte Progammierung in C++ - Schrader
 * Created Date: 2022-06-18, 6:10:20 pm
 * Author: Hamzenis Kryeziu
 * E-Mail: hamzenis.kryeziu@stud.fra-uas.de
 * -----
 * Last Modified: 2022-06-19, 1:35:37 am
 * Modified By: Hamzenis Kryeziu
 * -----
 * Copyright (c) 2022
 *
 * Free for use
 * -----
 * HISTORY:
 * Date              		By		Comments
 * ------------------		----	----------------------------------------------------------
 * 2022-06-19, 12:46:42 am	H.K.	v2
 * 2022-06-18, 7:06:17 pm	H.K.	v1
 * 2022-06-18, 6:10:20 pm	H.K.	-start-
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
    StudentRecords();
    vector<Student> getVecStudent();
    vector<Course> getVecCourse();
    vector<Grade> getVecGrade();
    string getCoursesName(int index);
    int getCoursesCredit(int index);
    string getStudentsName(int index);
    string getStudentsShortName(int index);
    int getStudentsSize();
    int getStudentsID(int index);
    int getCoursesSize();
    int getCoursesID(int index);
    void pushStudent(int id, string firstname, string lastname);
    void pushGrade(int studentid, int  courseid, float grade);
    void pushCourse(int id, string name, unsigned char credits);
    void printCourses();
    void printGrades();
    void printStudents();
    void printStudentRecord(int id);
    float calcGPA(int id);
    string convertToGrade(float inGrade);
};

/*------class functions------*/

//  parameterized constructor (vec students, vec courses, vec grades)
StudentRecords::StudentRecords(vector<Student> students, vector<Course> courses, vector<Grade> grades) {
    this->students = students;
    this->courses = courses;
    this->grades = grades;
}
//  default constructor
StudentRecords::StudentRecords() {
}

//  start of various getters
vector<Student> StudentRecords::getVecStudent() {
    return students;
}
vector<Course> StudentRecords::getVecCourse() {
    return courses;
}
vector<Grade> StudentRecords::getVecGrade() {
    return grades;
}
string StudentRecords::getCoursesName(int index) {
    return courses[index].getName();
}
int StudentRecords::getCoursesCredit(int index) {
    return courses[index].getCredits();
}
string StudentRecords::getStudentsName(int index) {
    return students[index].getName();
}
string StudentRecords::getStudentsShortName(int index) {
    return students[index].getShortName();
}
int StudentRecords::getStudentsSize() {
    return students.size();
}
int StudentRecords::getStudentsID(int index) {
    return students[index].getID();
}
int StudentRecords::getCoursesSize() {
    return courses.size();
}
int StudentRecords::getCoursesID(int index) {
    return courses[index].getID();
}
//  end of various getters

//  add a student(id, firstname, lastname)
void StudentRecords::pushStudent(int id, string firstname, string lastname) {
    Student a(id, firstname, lastname);
    students.push_back(a);
}
//  add a grade(sid, cid, grade)
void StudentRecords::pushGrade(int studentid, int  courseid, float grd) {
    Grade a(studentid, courseid, grd);
    grades.push_back(a);
}
//  add a course(id, name, credits)
void StudentRecords::pushCourse(int id, string name, unsigned char credits) {
    Course a(id, name, credits);
    courses.push_back(a);
}
//  prints all courses
void StudentRecords::printCourses() {
    for (Course& crs : courses) {
        cout << "Course ID: "
            << crs.getID()
            << " Name: " + crs.getName() + " Gewichtung: "
            << crs.getCredits()
            << endl;
    }
}
//  prints all grades
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
//  prints all students
void StudentRecords::printStudents() {
    for (Student& stdt : students) {
        cout << "Student ID: "
            << stdt.getID()
            << " Name: " + stdt.getName()
            << endl;
    }
}
//  prints the student record of a student only with the ID
void StudentRecords::printStudentRecord(int id) {
    //  finden des Studenten
    int iStudent = 0, iCourse = 0;
    while (iStudent < students.size() && students[iStudent].getID() != id)
        iStudent++;

    cout << students[iStudent].getName() + ": " << endl;
    for (Grade& grd : grades) {
        if (id == grd.getStudentID()) {
            iCourse = 0;
            while (iCourse < courses.size() && courses[iCourse].getID() != grd.getCourseID())
                iCourse++;
            cout << "Course ID: "
                << grd.getCourseID()
                << " Course name: "
                << courses[iCourse].getName()
                << " Note: " << convertToGrade(grd.getGrade()) << " ("
                << setprecision(3) << grd.getGrade() << ")" << endl;
        }
    }
    cout << "GPA: " << calcGPA(id) << endl;
}
//  calculate GPA
float StudentRecords::calcGPA(int id) {
    float courseCredits = 0.0f, sumGrades = 0.0f;
    int iCourse, iGrade;

    for (Grade& grd : grades) {
        if (id == grd.getStudentID()) {
            iCourse = 0;
            while (iCourse < courses.size() && courses[iCourse].getID() != grd.getCourseID())
                iCourse++;
            courseCredits += courses[iCourse].getCredits();
            sumGrades += courses[iCourse].getCredits() * grd.getGrade();
        }
    }

    return sumGrades / courseCredits;
}
//  converts the grades to strings in german grade notation
string StudentRecords::convertToGrade(float inGrade) {
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
//  End Classes

/*----------Functions----------*/

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

//  menue system to navigate the different options
int startMenue() {
    int imenue = 0;
    cout << "Waehle einen der folgenden Punkte aus: " << endl
        << "Student Record of a student(1)" << endl
        << "Add data(2)" << endl
        << "Print(3)" << endl
        << "Ihre Eingabe: ";
    cin >> imenue;
    return imenue;
}
int secMenue() {
    int imenue = 0;
    cout << "Welche Daten: "
        << "Student(1)\tCourse(2)\tGrade(3)"
        << endl << "Ihre Eingabe: ";
    cin >> imenue;
    return imenue;
}

/*----------main--------*/

int main() {
    int id, i, auswahl1, auswahl2;

    //  Objects
    StudentRecords example;

    //  data
    example.pushStudent(4, "Hamzenis", "Kryeziu");
    example.pushStudent(1, "George", "Burdell");
    example.pushStudent(2, "Nancy", "Rhodes");

    example.pushCourse(1, "Algebra", 5);
    example.pushCourse(2, "Physics", 4);
    example.pushCourse(3, "English", 3);
    example.pushCourse(4, "Economics", 4);

    example.pushGrade(4, 1, 1.3);
    example.pushGrade(4, 2, 1.5);
    example.pushGrade(4, 4, 3.0);
    example.pushGrade(4, 3, 2.3);
    example.pushGrade(1, 1, 2);
    example.pushGrade(1, 2, 1);
    example.pushGrade(1, 3, 3);
    example.pushGrade(2, 1, 1);
    example.pushGrade(2, 2, 2);
    example.pushGrade(2, 4, 2);


    //  Ausführung
    id = selectStudent();
    i = findStudent(example, id);
    notFoundCheck(i, example);

    //  menue system
    auswahl1 = startMenue();
    //  menue logic
    switch (auswahl1) {
        case 1:
            example.printStudentRecord(id);
            break;
        case 2:
            auswahl2 = secMenue();
            switch (auswahl2) {
                case 1:
                    break;
                default:
                    cout << "invalid option" << endl;
                    exit(1);
            }
            break;
        case 3:
            switch (auswahl2) {
                case 1:
                    break;
                default:
                    cout << "invalid option" << endl;
                    exit(1);
            }
            break;
        default:
            cout << "invalid option" << endl;
            exit(1);
    }
    cout << "end of programm" << endl;
    return (0);
}