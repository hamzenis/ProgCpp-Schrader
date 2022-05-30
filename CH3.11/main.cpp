/*
 * File: main.cpp
 * Project: Objektorientierte Progammierung in C++ - Schrader
 * Created Date: 2022-05-30, 11:25:50 am
 * Author: Hamzenis Kryeziu
 * E-Mail: hamzenis.kryeziu@stud.fra-uas.de
 * -----
 * Last Modified: 2022-05-30, 2:38:04 pm
 * Modified By: Hamzenis Kryeziu
 * -----
 * Copyright (c) 2022
 *
 * Free for use
 * -----
 * HISTORY:
 * Date              		By		Comments
 * ------------------		----	----------------------------------------------------------
 * 2022-05-30, 11:25:50 am	H.K.	-start-
 */

#include <iostream>
#include "Vorlesung.cpp"

int main() {
    Vorlesung neu(123, "CPP", "Schrader", 5, 4);
    neu.printObject();
    return 0;
}

