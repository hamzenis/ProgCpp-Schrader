/*
 * File: CH3.3.1.cpp
 * Project: Objektorientierte Progammierung in C++ - Schrader
 * Created Date: 2022-05-16, 10:13:05 am
 * Author: Hamzenis Kryeziu
 * E-Mail: hamzenis.kryeziu@stud.fra-uas.de
 * -----
 * Last Modified: 2022-05-16, 11:13:18 pm
 * Modified By: Hamzenis Kryeziu
 * -----
 * Copyright (c) 2022 
 * 
 * Free for use
 * -----
 * HISTORY:
 * Date              		By		Comments
 * ------------------		----	----------------------------------------------------------
 * 2022-05-16, 10:13:05 am	H.K.	-start-
 */

#include <iostream>
#include <string>

using namespace std;

struct datum {
    int year;
    int month;
    int day;
};

class student {

private:
    int stdtId;
    string lastname, firstname;
    string studiengang;
    datum gebDatum;

public:

    //  Constructor
    student(int id,
        string lname,
        string fname,
        string studgang,
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
    int getStdtId() {
        return stdtId;
    }
    string getLastname() {
        return lastname;
    }
    string getFirstname() {
        return firstname;
    }
    string getStudiengang() {
        return studiengang;
    }
    datum getDatum() {
        return gebDatum;
    }

    //  Setter
    void setStdtId(int id) {
        stdtId = id;
    }
    void setLastname(string lname) {
        lastname = lname;
    }
    void setFirstname(string fname) {
        firstname = fname;
    }
    void setStudiengang(string studgang) {
        studiengang = studgang;
    }
    void setDatum(datum gDate) {
        gebDatum = gDate;
    }

    //  Functions
    string getShortName() {
        string shortN;
        string halter = ". ";
        shortN = firstname[0] + lastname;
        shortN.insert(1, halter);
        return shortN;
    }

    //  Eine Print Funktion um einen schnellen Check auszuführen
    void printObject() {
        cout    << stdtId
                << " "
                << firstname + " "
                << lastname + " "
                << studiengang + " "
                << gebDatum.day
                << " "
                << gebDatum.month
                << " "
                << gebDatum.year
                << endl;
    }
};

int main() {

    //  Erstellen eines Objekts
    student my_Student(12345, "Kryeziu", "Hamzenis", "Informatik", 12, 12, 1998);
    
    //  Dummy Date fuer Tests
    datum mydate;
    mydate.day = 10;
    mydate.month = 10;
    mydate.year = 10;

    //  Printen des Objekts und Check der ShortName Funktion
    my_Student.printObject();
    cout << my_Student.getShortName() << endl;

    //  Test der Getter und Setter Funktion des Structs mit dem Geburtsdatum
    cout << my_Student.getDatum().year << endl;
    my_Student.setDatum(mydate);
    my_Student.printObject();

    return 0;
}