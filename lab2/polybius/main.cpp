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

int main() {
    cout << PolybiusCrypt("a b c d e f g h i j k l m n o p q r s t u v w x y z");
    //cout << PolybiusDecrypt("43 13 24 43 31 15 44 11 24 33 15");
}