#include "person.h"

using namespace std;

Person::Person(string fname, string lname) {
    this->fname = fname;
    this->lname = lname;
}

string Person::getName() {
    return fname + " " + lname;
}