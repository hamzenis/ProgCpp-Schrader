#pragma once

#ifndef PERSON_H_
#define PERSON_H_

#include <string>

class Person {

    protected:
        std::string lname;
        std::string fname;

    public:
        Person(std::string fname, std::string lname);
        std::string getName();

};


#endif