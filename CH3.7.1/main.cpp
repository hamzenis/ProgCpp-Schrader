/*
 * File: main.cpp
 * Project: Objektorientierte Progammierung in C++ - Schrader
 * Created Date: 2022-05-23, 10:16:53 am
 * Author: Hamzenis Kryeziu
 * E-Mail: hamzenis.kryeziu@stud.fra-uas.de
 * -----

 * Last Modified: 2022-06-03, 2:32:26 am

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
#include "Student.h"

using namespace std;

int main() {


    Student neu(1234, "Kryeziu", "Hamzenis", "Informatik", 12, 12, 2000);

    neu.printObject();

    cout << neu.getShortName() << endl;

    return 0;
}
