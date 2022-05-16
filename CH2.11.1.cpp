/*
 * File: CH2.11.1.cpp
 * Project: Objektorientierte Progammierung in C++ - Schrader
 * Created Date: 2022-05-09, 10:14:02 am
 * Author: Hamzenis Kryeziu
 * E-Mail: hamzenis.kryeziu@stud.fra-uas.de
 * -----
 * Last Modified: 2022-05-16, 11:47:57 pm
 * Modified By: Hamzenis Kryeziu
 * -----
 * Copyright (c) 2022 
 * 
 * Free for use
 * -----
 * HISTORY:
 * Date              		By		Comments
 * ------------------		----	----------------------------------------------------------
 * 2022-05-16, 11:46:06 pm	H.K.	added Comments
 * 2022-05-09, 10:14:02 am	H.K.	-start-
 */

#include <iostream>
#include <cmath>

using namespace std;


int main() {

    int aktuelleZahl = 2;
    char loopVar = 'n';
    int arrPrim[25];
    int index = 0;
    int flag = 0;

    cout << "Primzahlen bis 1000: Jeweils 25" << endl;

    do {
        
        while (true) {
            flag = 0;

            /*
            *   Check ob die aktuelle Zahl eine Primzahl ist,
            *   falls Sie es nicht ist wird die Flag Variable auf 1 gesetzt
            *   und in der folgenden if Anweisung nicht in das Array eingespeichert.
            */ 
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
            //  Wenn das Array voll ist wird die Schleife unterbrochen
            if (index == 25) {
                break;
            }
        }

        //  Printen des Arrays
        for (int i = 0; i < 25; i++) {
            cout << i+1 << ". "<< arrPrim[i] << endl;
        }

        /*
        *   Loop Aufforderung
        *   Es wird geloopt, solange die loopVar Variable 'y' ist und 
        *   die Zahl unter 1000 ist.
        *   Das Array wird wiederverwendet und die index Variable wird 
        *   auf 0 gesetzt. 
        */
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
