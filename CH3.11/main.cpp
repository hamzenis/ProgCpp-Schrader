/*
 * File: main.cpp
 * Project: Objektorientierte Progammierung in C++ - Schrader
 * Created Date: 2022-05-30, 11:25:50 am
 * Author: Hamzenis Kryeziu
 * E-Mail: hamzenis.kryeziu@stud.fra-uas.de
 * -----
 * Last Modified: 2022-06-03, 1:19:03 am
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
#include "Vorlesung.h"
#include <vector>

/*
*   Print Funktion für den Vector von Objekten "Vorlesung"
*/
void printVector(std::vector<Vorlesung> a) {
    std::cout << std::endl;
    for (int i = 0; i < a.size(); i++) {
        a[i].printObject();
    }
}

int main() {

    char menueChar = 'n';
    std::string name, dozent;
    int id, ect, sws;
    std::vector<Vorlesung> uebersicht;

    //  Eingabeschleife
    do {
        std::cout << "Geben Sie den Namen Ihrer Vorlesung ein: ";
        std::cin >> name;
        std::cout << "Geben Sie die ID Ihrer Vorlesung ein: ";
        std::cin >> id;
        std::cout << "Geben Sie den Namen Ihres Dozent ein: ";
        std::cin >> dozent;
        std::cout << "Geben Sie die ECT an: ";
        std::cin >> ect;
        std::cout << "Geben Sie die Semesterwochenstunden an: ";
        std::cin >> sws;

        Vorlesung eingabe(id, name, dozent, ect, sws);
        uebersicht.push_back(eingabe);

        std::cout << "Möchten Sie weitere Vorlesungen listen? (y/n)";
        std::cin >> menueChar;

    } while (menueChar == 'y');

    printVector(uebersicht);

    return 0;
}

