/*
 * File: Student.cpp
 * Project: Objektorientierte Progammierung in C++ - Schrader
 * Created Date: 2022-05-23, 10:16:35 am
 * Author: Hamzenis Kryeziu
 * E-Mail: hamzenis.kryeziu@stud.fra-uas.de
 * -----
 * Last Modified: 2022-05-24, 1:07:25 am
 * Modified By: Hamzenis Kryeziu
 * -----
 * Copyright (c) 2022
 *
 * Free for use
 * -----
 * HISTORY:
 * Date              		By		Comments
 * ------------------		----	----------------------------------------------------------
 * 2022-05-23, 10:16:35 am	H.K.	-start-
 */

#include "Student.h"
#include <iostream>
#include <iomanip>

 //  Constructor
Student::Student(int id,
                std::string lname,
                std::string fname,
                std::string studgang,
                int day,
                int month,
                int year) {
    stdtId = id;
    lastname = lname;
    firstname = fname;
    studiengang = studgang;
    gebDatum.day = day;
    gebDatum.month = month;
    gebDatum.year = year;
}

//  Getter
int Student::getStdtId() {
    return stdtId;
}
std::string Student::getLastname() {
    return lastname;
}
std::string Student::getFirstname() {
    return firstname;
}
std::string Student::getStudiengang() {
    return studiengang;
}
Birthday Student::getDatum() {
    return gebDatum;
}

//  Setter
void Student::setStdtId(int id) {
    stdtId = id;
}
void Student::setLastname(std::string lname) {
    lastname = lname;
}
void Student::setFirstname(std::string fname) {
    firstname = fname;
}
void Student::setStudiengang(std::string studgang) {
    studiengang = studgang;
}
void Student::setDatum(Birthday gDate) {
    gebDatum = gDate;
}

//  Functions
std::string Student::getShortName() {
    std::string shortN;
    shortN = firstname[0] + lastname;
    shortN.insert(1, ". ");
    return shortN;
}

//  Eine Print Funktion um einen schnellen Check auszuführen
void Student::printObject() {
    std::cout   << stdtId
                << " "
                << firstname + " "
                << lastname + " "
                << studiengang + " "
                << gebDatum.day
                << " "
                << gebDatum.month
                << " "
                << gebDatum.year
                << std::endl;
}