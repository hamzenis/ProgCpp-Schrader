/*
 * File: Vorlesung.cpp
 * Project: Objektorientierte Progammierung in C++ - Schrader
 * Created Date: 2022-05-30, 10:56:42 am
 * Author: Hamzenis Kryeziu
 * E-Mail: hamzenis.kryeziu@stud.fra-uas.de
 * -----
 * Last Modified: 2022-05-30, 1:53:34 pm
 * Modified By: Hamzenis Kryeziu
 * -----
 * Copyright (c) 2022
 *
 * Free for use
 * -----
 * HISTORY:
 * Date              		By		Comments
 * ------------------		----	----------------------------------------------------------
 * 2022-05-30, 10:56:42 am	H.K.	-start-
 */

#include "Vorlesung.h"
#include <iostream>

 //  Constructor
Vorlesung::Vorlesung(int id,
    std::string name,
    std::string dozent,
    int ect,
    int sws) {
    this->id = id;
    this->name = name;
    this->dozent = dozent;
    this->ect = ect;
    this->sws = sws;
}

//  Getter
int Vorlesung::getId() {
    return id;
}
std::string Vorlesung::getName() {
    return name;
}
std::string Vorlesung::getDozent() {
    return dozent;
}
int Vorlesung::getEct() {
    return ect;
}
int Vorlesung::getSws() {
    return sws;
}

//  Setter
void Vorlesung::setId(int id) {
    this->id = id;
}
void Vorlesung::setName(std::string name) {
    this->name = name;
}
void Vorlesung::setDozent(std::string dozent) {
    this->dozent = dozent;
}
void Vorlesung::setEct(int ect) {
    this->ect = ect;
}
void Vorlesung::setSws(int sws) {
    this->sws = sws;
}

//  Funktionen
void Vorlesung::printObject() {
    std::cout   << id
                << " "
                << name + " "
                << dozent + " "
                << ect
                << " "
                << sws
                << std::endl;
}
