/*
 * File: student.h
 * Project: Objektorientierte Progammierung in C++ - Schrader
 * Created Date: 2022-05-23, 10:15:39 am
 * Author: Hamzenis Kryeziu
 * E-Mail: hamzenis.kryeziu@stud.fra-uas.de
 * -----

 * Last Modified: 2022-05-30, 10:28:24 am

 * Modified By: Hamzenis Kryeziu
 * -----
 * Copyright (c) 2022 
 * 
 * Free for use
 * -----
 * HISTORY:
 * Date              		By		Comments
 * ------------------		----	----------------------------------------------------------
 * 2022-05-23, 10:15:39 am	H.K.	-start-
 */


#pragma once

#ifndef STUDENT_H
#define STUDENT_H



struct Birthday{
    int year;
    int month;
    int day;
};

class Student {

private:
    int stdtId;
    std::string lastname;
    std::string firstname;
    std::string studiengang;
    Birthday gebDatum;

public:

    //  Constructor
    Student(int id,
            std::string lname,
            std::string fname,
            std::string studgang,
            int day,
            int month,
            int year);

    //  Getter
    int getStdtId();
    std::string getLastname();
    std::string getFirstname();
    std::string getStudiengang();
    Birthday getDatum();


    //  Setter
    void setStdtId(int id);
    void setLastname(std::string lname);
    void setFirstname(std::string fname);
    void setStudiengang(std::string studgang);
    void setDatum(Birthday gDate);

    //  Functions
    std::string getShortName();
    void printObject();
};

#endif

