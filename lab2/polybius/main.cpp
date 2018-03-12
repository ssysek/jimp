//
// Created by Jan on 12.03.2018.
//
#include <iostream>
#include <string>
#include <fstream>
#include "Polybius.h"

using namespace std;

//PODZIELIĆ PLIK NA STRINGI Z LINIJKAMI
//USUNAĆ SPACJE Z LINIJEK
//USUNAĆ POLSKIE ZNAKI
//ZAMIENIĆ J NA I
string change(string mg)
{
    string changed="";
    char tmp;
    for (int i=0;i<mg.length();i++)
    {
        tmp=(char)(toupper(mg[i]));
        switch(tmp)
        {
            case 'J':
                changed+='I';
                break;
            case ' ':
                break;
            default:
                changed+=tmp;
                break;
        }
    }

    return changed;
}