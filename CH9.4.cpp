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
