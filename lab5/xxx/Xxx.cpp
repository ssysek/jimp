//
// Created by zasadjan on 27.03.18.
//

#include "Xxx.h"
using namespace std;

//konstruktor kopiujący:
XXX::XXX(const XXX& xxx) {
    size_t sz = xxx.name_.length();
    name_ = new char[sz];
    strcpy(name_,xxx.name_);
    //Teraz nowy obiekt pokazuje na nowy fragment pamięci,
    //ale ze skopiowaną informacją
}
//operator przypisania:
XXX & XXX::operator=(const XXX& xxx) {
    //jeśli ktoś wpadł na pomysł x = x;
    if (this == &xxx) {
        return *this;
    }
    //w przyciwynym wypadku mamy x = y;
    //musimy sami zwolnic pamięć po x (czyli this):
    delete[] name_;
    //i wreszcie kopiowanie, ten kod jest
    //jest identyczny więc można by go wydzielić do innej metody...
    size_t sz = strlen(xxx.name_);
    name_ = new char[sz];
    strcpy(name_,xxx.name_);
}

