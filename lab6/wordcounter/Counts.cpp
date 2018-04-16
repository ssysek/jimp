//
// Created by Jan on 16.04.2018.
//

#include "Counts.h"
using namespace datastructures;

Counts & Counts::operator++() {

    licznik++;
    return *this;

}

Counts::Counts(int numer) {

    licznik = numer;

}

bool Counts::operator==(Counts zlicz) const {

    return (licznik==zlicz.licznik);

}

bool Counts::operator>(Counts zlicz) const {

    return (licznik>zlicz.licznik);

}

bool Counts::operator<(Counts zlicz) const {

    return (licznik<zlicz.licznik);

}



