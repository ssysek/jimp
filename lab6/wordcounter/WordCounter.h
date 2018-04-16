//
// Created by Jan on 16.04.2018.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <vector>
#include <set>
#include "Counts.h"
#include "Word.h"


namespace datastructures {


    class WordCounter {
    public:
        WordCounter() = default;

        WordCounter(const std::initializer_list<Word> &elements);

        int DistinctWords();

        int TotalWords();

        void InsertWord(const std::string word);

        std::set<Word> Words();

        static WordCounter &FromInputStream(std::istream &is);

        friend std::ostream &operator<<(std::ostream &stream, WordCounter &wc);

        int operator[](const std::string &);

    private:
        std::vector<std::pair<Word, Counts>> wordVector_;
    };
}

#endif JIMP_EXERCISES_WORDCOUNTER_H
