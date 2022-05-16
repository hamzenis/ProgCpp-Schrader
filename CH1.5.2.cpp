/*
 * File: CH1.5.2.cpp
 * Project: Objektorientierte Progammierung in C++ - Schrader
 * Created Date: 2022-04-25, 10:36:54 am
 * Author: Hamzenis Kryeziu
 * E-Mail: hamzenis.kryeziu@stud.fra-uas.de
 * -----
 * Last Modified: 2022-05-16, 11:10:45 pm
 * Modified By: Hamzenis Kryeziu
 * -----
 * Copyright (c) 2022 
 * 
 * Free for use
 * -----
 * HISTORY:
 * Date              		By		Comments
 * ------------------		----	----------------------------------------------------------
 * 2022-04-25, 10:36:54 am	H.K.	-start-
 */

#include <iostream>

using namespace std;

int main() {
    int j = 1;
    int count = 0;
    cout << "April 2022" << endl;
    cout << "Mo\tDi\tMi\tDo\tFr\tSa\tSo" << endl;

    for (int i = 1; i < 31+4; i++) {
        if(count == 7){
            count = 0;
            cout<<endl;
        }    
        if (i<5) {
            cout<<"\t";
            count++;
        }
        else{
            cout<< j <<"\t";
            j++;
            count++;
        }
    }
    cout<<endl;
    return 0;
}
