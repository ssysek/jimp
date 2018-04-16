//
// Created by Jan on 16.04.2018.
//

#include "Word.h"
using datastructures::Word;

Word::Word(string str) {

    szukane = str;

}

bool Word::operator==(Word zlicz) const {

    return (szukane==zlicz.szukane);

}

bool Word::operator>(Word zlicz) const {

    return (szukane>zlicz.szukane);

}

bool Word::operator<(Word zlicz) const {

    return (szukane<zlicz.szukane);

}

