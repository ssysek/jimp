//
// Created by Jan on 16.04.2018.
//

#include "Word.h"
using datastructures::Word;

Word::Word(string str)
{
    searched_word = str;
}

bool Word::operator<(Word ignas) const {
    return (searched_word<ignas.searched_word);
}

bool Word::operator>(Word ignas) const {
    return (searched_word>ignas.searched_word);
}

bool Word::operator==(Word ignas) const {
    return (searched_word==ignas.searched_word);
}