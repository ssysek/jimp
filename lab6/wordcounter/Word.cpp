//
// Created by Jan on 16.04.2018.
//

#include "Word.h"

namespace datastructures {

    Word::Word(const std::string &str = "") {
        word_ = str;
    }

    const std::string &Word::GetWord() const { return word_; }
}