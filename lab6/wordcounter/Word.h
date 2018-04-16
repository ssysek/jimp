//
// Created by Jan on 16.04.2018.
//

#ifndef JIMP_EXERCISES_WORD_H
#define JIMP_EXERCISES_WORD_H

#include <string>

namespace datastructures {
    class Word {
    public:
        Word() = default;

        Word(const std::string &str);

        const std::string &GetWord() const;

    private:
        std::string word_;
    };

}

#endif //JIMP_EXERCISES_WORD_H
