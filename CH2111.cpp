/*
 * File: CH2111.cpp
 * Project: Objektorientierte Progammierung in C++ - Schrader
 * Created Date: 2022-05-09, 10:14:02 am
 * Author: Hamzenis Kryeziu
 * E-Mail: hamzenis.kryeziu@stud.fra-uas.de
 * -----
 * Last Modified: 2022-05-16, 8:19:45 pm
 * Modified By: Hamzenis Kryeziu
 * -----
 * Copyright (c) 2022 
 * 
 * Free for use
 * -----
 * HISTORY:
 * Date              		By		Comments
 * ------------------		----	----------------------------------------------------------
 * 2022-05-09, 10:14:02 am	H.K.	-start-
 */

#include <iostream>
#include <cmath>

using namespace std;


int main() {

    int countArr = 0;
    int aktuelleZahl = 2;
    char loopVar = 'n';
    int arrPrim[25];
    int index = 0;

    cout << "Primzahlen: Jeweils 25" << endl;

    do {
        while (true) {
            int flag = 0;
            for (int i = 2; i < aktuelleZahl; i++) {
                if ((aktuelleZahl % i == 0)) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                arrPrim[index++] = aktuelleZahl;
            }
            aktuelleZahl++;
            if (index == 25) {
                break;
            }
        }

        for (int i = 0; i < 25; i++) {
            cout << i+1 << ". "<< arrPrim[i] << endl;
        }

        //  Loop Aufforderung
        if (aktuelleZahl <= 1000) {
            cout << "Wollen Sie weitere 25 Primzahlen ausgeben lassen? (y/n)" << endl;
            cin >> loopVar;
            index = 0;
        }
        else {
            loopVar = 'n';
        }
    } while (loopVar == 'y');


    return 0;
}
