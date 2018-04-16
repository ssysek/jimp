//
// Created by Jan on 16.04.2018.
//

#include "Counts.h"
using namespace datastructures;

Counts & Counts::operator++() {
    count++;
    return *this;
}

Counts::Counts(int number) {
    count = number;
}

bool Counts::operator<(Counts ignas) const {
    return (count<ignas.count);
}

bool Counts::operator>(Counts ignas) const {
    return (count>ignas.count);
}

bool Counts::operator==(Counts ignas) const {
    return (count==ignas.count);
}