//
// Created by Jan on 16.04.2018.
//

#include "WordCounter.h"
using datastructures::WordCounter;
using datastructures::Word;

int WordCounter::TotalWords() {

    return suma;

}

int WordCounter::DistinctWords() {

    return unikat;

}

WordCounter::WordCounter(initializer_list<Word> words) {

    suma = 0;
    unikat = 0;
    int temp = 0;
    bool flaga;
    for (auto slowo : words) {

        suma++;
        flaga = true;
        temp = 0;
        for(pair<Word, Counts> iter : talista) {

            if (iter.first.szukane == slowo.szukane) {

                ++find(talista.begin(),talista.end(),iter)->second;
                flaga = false;
                break;

            }
            temp++;
        }

        if (flaga) {

            Counts i{1};
            unikat++;
            talista.emplace_back(std::make_pair(slowo,i));

        }
    }
}

int WordCounter::operator[](string szukany) {
    for(auto h : talista) {

        if(h.first.szukane == szukany){

            return h.second.licznik;

        }

    }

    return 0;

}

set<Word> WordCounter::Words() {

    list<int> lista;
    for(auto i : talista){

        lista.emplace_back(i.second.licznik);

    }
    lista.sort();

    map<Word, Counts> mapa;
    for(auto j : talista){

        mapa.emplace(j.first, j.second);

    }

    set<Word> _set;
    for(int iter : lista) {

        for(auto element : mapa) {

            if (iter == element.second.licznik) {

                _set.emplace(element.first);
                element.second.licznik=-1;

            }
        }
    }
    return _set;
}

WordCounter::WordCounter() {

    suma = 0;
    unikat = 0;
}
