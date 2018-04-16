//
// Created by Jan on 16.04.2018.
//

#include <iostream>
#include "WordCounter.h"
using datastructures::WordCounter;
using datastructures::Word;


int main()
{
    WordCounter counter {Word("a"), Word("p"), Word("a"), Word("a"), Word("hi"), Word("voltage")};
    std::set<Word> secik;
    secik = counter.Words();
    std::cout<<"o";

    return 0;
}