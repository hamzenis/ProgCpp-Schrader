/*
 * File: CH9.4.cpp
 * Project: Objektorientierte Progammierung in C++ - Schrader
 * Created Date: 2022-07-08, 6:27:12 pm
 * Author: Julian Siefert
 * E-Mail:
 * -----
 * Last Modified: 2022-07-08, 9:04:18 pm
 * Modified By: Hamzenis Kryeziu
 * -----
 * Copyright (c) 2022 
 * 
 * Free for use
 * -----
 * HISTORY:
 * Date              		By		Comments
 * ------------------		----	----------------------------------------------------------
 */


#include <iostream>
using namespace std;
class person{
protected:
	string name;
public:
	person(string iname){
		name = iname;
	}
	string getname(){
		return name;
	}
};
class student: public person{
private:
	string semester;
public:
	student(string iname, string isemester):person(name){
		name = iname;
		semester = isemester;
	}
	string getsemester(){
	return semester;
	}

};
int main() {
	person 	vater("Schmidt");
	student sohn("Schmidt","Sommersemester");

	cout << "Nachname des Vaters: " << vater.getname() << endl;
	cout << "Nachname des Studenten : " << sohn.getname() <<endl << " Semster des Studenten " << sohn.getsemester() << endl;

	return 0;
}
