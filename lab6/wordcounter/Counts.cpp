//
// Created by Jan on 16.04.2018.
//

#include "Counts.h"


using namespace datastructures;

Counts & Counts::operator++() {
    count++;
    return *this;
}


Counts::Counts(int numer) {
    count = numer;
}


bool Counts::operator==(Counts zlicz) const {
    return (count==zlicz.count);
}


bool Counts::operator>(Counts zlicz) const {
    return (count>zlicz.count);
}


bool Counts::operator<(Counts zlicz) const {
    return (count<zlicz.count);
}
