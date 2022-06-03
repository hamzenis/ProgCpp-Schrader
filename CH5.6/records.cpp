#include "records.h"

using namespace std;

Student::Student(int the_id, string the_fname, string the_lname) {
	id = the_id;
	fname = the_fname;
	lname = the_lname;
}
int Student::getID() {
	return id;
}
string Student::getName() {
	return fname + " " +lname;
}

string Student::getShortName() {
	return lname + ", " += fname[0];
}

Course::Course(int the_id, string the_name, unsigned char the_credits) {
	id = the_id;
	name = the_name;
	credits = the_credits;
}
int Course::getID() {
	return id;
}
string Course::getName() {
	return name;
}
int Course::getCredits() {
	return credits;
}


Grade::Grade(int sid, int cid, float grd) {
	student_id = sid;
	course_id = cid;
	grade = grd;
}
int Grade::getStudentID() {
	return student_id;
}
int Grade::getCourseID() {
	return course_id;
}
float Grade::getGrade() {
	return grade;
}

