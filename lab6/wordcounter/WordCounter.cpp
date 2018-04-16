//
// Created by Jan on 16.04.2018.
//

#include <iostream>
#include "WordCounter.h"
#include <algorithm>

namespace datastructures {

    WordCounter::WordCounter(const std::initializer_list<Word> &elements) {
        for (auto w : elements) {
            bool found = false;
            for (auto it = wordVector_.begin(); it != wordVector_.end(); ++it) {
                if (w == it->first) {
                    ++it->second;
                    found = true;
                    break;
                }
            }
            if (!found) {
                std::pair<Word, Counts> new_pair = std::make_pair(w, Counts(1));
                wordVector_.push_back(new_pair);
            }
        }
    }

    int WordCounter::DistinctWords() {
        return (int)wordVector_.size();
    }

    int WordCounter::TotalWords() {
        int result = 0;
        for (auto &word : wordVector_)
            result += word.second.GetCount();
        return result;
    }

    std::set<Word> WordCounter::Words() {
        std::set<Word> wordSet;

        for (auto &word: wordVector_)
            wordSet.insert(word.first);

        return wordSet;
    }

    WordCounter &WordCounter::FromInputStream(std::istream &is) {
        static WordCounter wordCounter;
        std::string word;
        while (is >> word)
            wordCounter.InsertWord(word);
        return wordCounter;
    }

    void WordCounter::InsertWord(const std::string word) {
        bool found = false;
        for (auto it = wordVector_.begin(); it != wordVector_.end(); ++it) {
            if (word == it->first) {
                ++it->second;
                found = true;
                break;
            }
        }
        if (!found) {
            std::pair<Word, Counts> new_pair = std::make_pair(Word(word), Counts(1));
            wordVector_.push_back(new_pair);
        }
    }


    std::ostream &operator<<(std::ostream &stream, WordCounter &wc) {
        stream << "Words: " << wc.DistinctWords() << std::endl;
        std::vector<std::pair<Word, Counts>> vec = wc.wordVector_;
        std::sort(vec.begin(), vec.end());
        for (auto it = vec.begin(); it != vec.end(); ++it) {
            stream << it->first.GetWord() << ": " << it->second.GetCount() << std::endl;
        }

        return stream;
    }

    int WordCounter::operator[](const std::string &str) {
        int result = 0;
        for (auto &word: wordVector_) {
            if (word.first.GetWord() == str) {
                result = word.second.GetCount();
                break;
            }
        }
        return result;
    }
}