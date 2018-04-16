//
// Created by Jan on 16.04.2018.
//

//
// Created by Jan on 16.04.2018.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include "string"
#include "iostream"
#include "Word.h"
#include "Counts.h"
#include "list"
#include "fstream"
#include "map"
#include <utility>
#include <regex>
#include <initializer_list>
#include <set>

using std::map;
using std::string;
using std::set;
using std::cout;
using std::endl;
using std::pair;
using std::list;
using std::initializer_list;
namespace datastructures {


    class WordCounter {

    public:

        WordCounter();
        WordCounter(initializer_list<Word> words);
        ~WordCounter() {};

        int operator[](string szukany);
        int DistinctWords();
        int TotalWords();
        set<Word> Words();

    private:

        list<pair<Word, Counts>> talista;
        int unikat;
        int suma;

    };


}
#endif //JIMP_EXERCISES_WORDCOUNTER_H