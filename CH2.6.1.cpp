/*
 * File: CH2.6.1.cpp
 * Project: Objektorientierte Progammierung in C++ - Schrader
 * Created Date: 2022-05-02, 10:45:14 am
 * Author: Hamzenis Kryeziu
 * E-Mail: hamzenis.kryeziu@stud.fra-uas.de
 * -----
 * Last Modified: 2022-05-16, 11:16:27 pm
 * Modified By: Hamzenis Kryeziu
 * -----
 * Copyright (c) 2022 
 * 
 * Free for use
 * -----
 * HISTORY:
 * Date              		By		Comments
 * ------------------		----	----------------------------------------------------------
 * 2022-05-02, 10:45:14 am	H.K.	-start-
 */

#include <iostream>

using namespace std;

int main() {

    float listeneinkaufspreis;
    int rabatt;
    int skonto;
    float bezugskosten;
    int handlungskostensatz;
    int gewinnzuschlag;



    cout << "Bitte Geben Sie die Werte ein" << endl << endl << "Eingabe" << endl;
    cout << "Listeneinkaufspreis: ";
    cin >> listeneinkaufspreis;

    cout << "Rabatt (in %)!: ";
    cin >> rabatt;

    cout << "Skonto(in %): ";
    cin >> skonto;

    cout << "Bezugskosten: ";
    cin >> bezugskosten;

    cout << "Handlungskostensatz (in %): ";
    cin >> handlungskostensatz;

    cout << "Gewinnzuschlag (in %): ";
    cin >> gewinnzuschlag;

    return 0;
}