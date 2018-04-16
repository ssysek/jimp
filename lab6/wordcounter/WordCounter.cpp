//
// Created by Jan on 16.04.2018.
//

#include "WordCounter.h"
using datastructures::WordCounter;
using datastructures::Word;

WordCounter::WordCounter(initializer_list<Word> words) {
    total = 0;
    distinct = 0;
    int tmp = 0;
    bool flag;
    for (auto word : words)
    {
        total++;
        flag = true;
        tmp = 0;
        for(pair<Word, Counts> iter : mylist)
        {
            if (iter.first.searched_word == word.searched_word)
            {
                ++find(mylist.begin(),mylist.end(),iter)->second;
                flag = false;
                break;
            }
            tmp++;
        }

        if (flag)
        {
            Counts oo{1};
            distinct++;
            mylist.emplace_back(std::make_pair(word,oo));
        }
    }
}

int WordCounter::DistinctWords() {
    return distinct;
}

int WordCounter::TotalWords() {
    return total;
}

int WordCounter::operator[](string wanted) {
    for(auto iter : mylist)
    {
        if(iter.first.searched_word == wanted)
            return iter.second.count;
    }
    return 0;
}

set<Word> WordCounter::Words() {

    list<int> lista;
    for(auto iter : mylist)
        lista.emplace_back(iter.second.count);
    lista.sort();

    map<Word, Counts> mapka;
    for(auto iter : mylist)
        mapka.emplace(iter.first, iter.second);

    set<Word> _set;
    for(int iter : lista)
    {
        for(auto em_el : mapka)
        {
            if (iter == em_el.second.count)
            {
                _set.emplace(em_el.first);
                em_el.second.count=-1;
            }
        }
    }
    return _set;
}

WordCounter::WordCounter() {

    total = 0;
    distinct = 0;
}
