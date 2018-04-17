//
// Created by Jan on 16.04.2018.
//

#ifndef JIMP_EXERCISES_WORD_H
#define JIMP_EXERCISES_WORD_H

#include "string"

using std::string;

namespace datastructures {


    class Word {

    public:

        friend class WordCounter;

        Word(){};

        Word(string str);

        ~Word() {};

        bool operator==(Word zlicz) const ;
        bool operator>(Word zlicz) const ;
        bool operator<(Word zlicz) const ;

    private:

        string szukane;

    };

}
#endif //JIMP_EXERCISES_WORD_H
