/*
 * File: Vorlesung.h
 * Project: Objektorientierte Progammierung in C++ - Schrader
 * Created Date: 2022-05-30, 10:26:27 am
 * Author: Hamzenis Kryeziu
 * E-Mail: hamzenis.kryeziu@stud.fra-uas.de
 * -----
 * Last Modified: 2022-06-03, 1:21:17 am
 * Modified By: Hamzenis Kryeziu
 * -----
 * Copyright (c) 2022
 *
 * Free for use
 * -----
 * HISTORY:
 * Date              		By		Comments
 * ------------------		----	----------------------------------------------------------
 * 2022-05-30, 10:26:27 am	H.K.	-start-
 */

#pragma once

#ifndef VORLESUNG_H
#define VORLESUNG_H

#include <iostream>

class Vorlesung {

private:
    int id;
    std::string name;
    std::string dozent;
    int ect;
    int sws;

public:
    //  Constructor
    Vorlesung(int id,
        std::string name,
        std::string dozent,
        int ect,
        int sws);

    //  Getter
    int getId();
    std::string getName();
    std::string getDozent();
    int getEct();
    int getSws();

    //  Setter
    void setId(int id);
    void setName(std::string name);
    void setDozent(std::string dozent);
    void setEct(int ect);
    void setSws(int sws);

    //  Funktionen
    void printObject();

};

#endif