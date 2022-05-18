/*
 * File: CH2.11.2.cpp
 * Project: Objektorientierte Progammierung in C++ - Schrader
 * Created Date: 2022-05-18, 2:27:45 pm
 * Author: Hamzenis Kryeziu
 * E-Mail: hamzenis.kryeziu@stud.fra-uas.de
 * -----
 * Last Modified: 2022-05-19, 1:19:38 am
 * Modified By: Hamzenis Kryeziu
 * -----
 * Copyright (c) 2022
 *
 * Free for use
 * -----
 * HISTORY:
 * Date              		By		Comments
 * ------------------		----	----------------------------------------------------------
 * 2022-05-19, 1:18:29 am	H.K.	added comments
 * 2022-05-18, 2:27:45 pm	H.K.	-start-
 */

#include <iostream>
#include <iomanip>

using namespace std;

//  Berechnung des Kapitals nach Zinsen
float berechnen(float kapital, float zinssatz) {
    float berechnung;
    berechnung = kapital * (1+(zinssatz / 100));
    return berechnung;
}

int main() {

    float ikapital;
    float fzinssatz;
    int ilaufzeit;

    cout << "Bitte geben Sie ihr Kapital ein: ";
    cin >> ikapital;
    cout << "Bitte geben Sie ihren Zinssatz ein (in %): ";
    cin >> fzinssatz;
    cout << "Bitte geben Sie ihre Laufzeit ein: ";
    cin >> ilaufzeit;

    cout    << right << setw(10) << "Jahr" 
            << right << setw(10) << "Kapital" 
            << endl;

    for (int i = 0; i < ilaufzeit; i++) {
        ikapital = berechnen(ikapital, fzinssatz);
        cout    << right << setw(10) << i+1
                << right << setw(10) << fixed << setprecision(2) << ikapital
                << endl;
    }

    return 0;
}