/*
 * File: CH2.6.1.cpp
 * Project: Objektorientierte Progammierung in C++ - Schrader
 * Created Date: 2022-05-02, 10:45:14 am
 * Author: Hamzenis Kryeziu
 * E-Mail: hamzenis.kryeziu@stud.fra-uas.de
 * -----
 * Last Modified: 2022-05-17, 1:14:05 am
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

void printTable(float l, int r, int s, float b, int h, int g) {
    cout << l
        << endl
        << r
        << endl
        << s
        << endl
        << b
        << endl
        << h
        << endl
        << g
        << endl;
}
/*
*   CSI[2J clears screen, CSI[H moves the cursor to top-left corner
*   -
*   Source: Stackoverflow
*/
void clear() {
    std::cout << "\x1B[2J\x1B[H";
}


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


    cout << "Hit Enter." << endl;
    std::cin.ignore();
    std::cin.ignore();
    clear();
    printTable(
        listeneinkaufspreis,
        rabatt,
        skonto,
        bezugskosten,
        handlungskostensatz,
        gewinnzuschlag
        );

    
    return 0;
}