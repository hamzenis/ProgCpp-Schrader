#pragma once

#ifndef STUDENT_H_
#define STUDENT_H_

#include "person.h"
#include <string>

class Student : public Person {
    private:
        std::string semester;
    public:
        Student(std::string fname, std::string lname, std::string semester);
        std::string getSemester();
        
};

#endif