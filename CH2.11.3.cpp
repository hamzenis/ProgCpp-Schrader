/*
 * File: CH2.11.3.cpp
 * Project: Objektorientierte Progammierung in C++ - Schrader
 * Created Date: 2022-05-14, 1:15:38 pm
 * Author: Hamzenis Kryeziu
 * E-Mail: hamzenis.kryeziu@stud.fra-uas.de
 * -----
 * Last Modified: 2022-05-19, 10:03:06 pm
 * Modified By: Hamzenis Kryeziu
 * -----
 * Copyright (c) 2022
 *
 * Free for use
 * -----
 * HISTORY:
 * Date              		By		Comments
 * ------------------		----	----------------------------------------------------------
 * 2022-05-19, 9:51:16 pm	H.K.	extended ASCII Table is not printing right,
 *                                  ASCII Characters up to 127 are working
 * 2022-05-14, 1:15:38 pm	H.K.	-start-
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    for (int i = 32; i < 256; i++) {
        cout << right << setw(5) << i << " =\t";
        cout << (char) i << "\t"; 
        if (i % 6 == 0) {
            cout << endl;
        }
    }

    return 0;
}