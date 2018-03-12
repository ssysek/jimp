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
    cout << PolybiusCrypt("SCISLE TAJNE");
    cout << PolybiusDecrypt("43 13 24 43 31 15 44 11 24 33 15");
}