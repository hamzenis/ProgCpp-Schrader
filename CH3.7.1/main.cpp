/*
 * File: main.cpp
 * Project: Objektorientierte Progammierung in C++ - Schrader
 * Created Date: 2022-05-23, 10:16:53 am
 * Author: Hamzenis Kryeziu
 * E-Mail: hamzenis.kryeziu@stud.fra-uas.de
 * -----
 * Last Modified: 2022-05-30, 10:05:15 am
 * Modified By: Hamzenis Kryeziu
 * -----
 * Copyright (c) 2022
 *
 * Free for use
 * -----
 * HISTORY:
 * Date              		By		Comments
 * ------------------		----	----------------------------------------------------------
 * 2022-05-23, 10:16:53 am	H.K.	-start-
 */

#include <iostream>
#include <string>
#include "Student.cpp"

using namespace std;

int main() {

    Student neu(1234, "Kryeziu", "Hamzenis", "Informatik", 28, 10, 1998);

    neu.printObject();

    cout << neu.getShortName() << endl;

    return 0;
}
