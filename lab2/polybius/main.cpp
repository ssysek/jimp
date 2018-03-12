//
// Created by Jan on 12.03.2018.
//
#include <iostream>
#include <string>
#include "Polybius.h"

using namespace std;

//PODZIELIĆ PLIK NA STRINGI Z LINIJKAMI
//USUNAĆ SPACJE Z LINIJEK
//USUNAĆ POLSKIE ZNAKI
//ZAMIENIĆ J NA I
int main() {

    string test="SCISLETAINE";

    cout << PolybiusCrypt(test);

    return 0;
}