#pragma once

#ifndef RECORDS_H_
#define RECORDS_H_

#include <string>

class Student {
private:
	int id;
	std::string fname;
	std::string lname;

public:
	Student(int the_id, std::string the_fname, std::string the_lname);
	int getID();
	std::string getName();
	std::string getShortName();
};

class Course {
private:
	int id;
	std::string name;
	unsigned char credits;

public:
	Course(int the_id, std::string the_name, unsigned char the_credits);
	int getID();
	std::string getName();
	int getCredits();
};

class Grade {
private:
	int student_id;
	int course_id;
	float grade;

public:
	Grade(int sid, int cid, float grd);
	int getStudentID();
	int getCourseID();
	float getGrade();
};

#endif
