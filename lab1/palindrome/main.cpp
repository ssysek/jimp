//
// Created by Jan on 05.03.2018.
//
#include <iostream>
#include <string>
#include "Palindrome.h"


int main(){

    std::cout << "Podaj opcje: 1-Test na palindrom 0-Wyjście";
    int opcja;
    std::cin >> opcja;
    if(opcja==1){
        std::cout << "Podaj tekst";
        std::string tekst;
        std::cin >> tekst;
        if(IsPalindrome(tekst)==1){
            std::cout << "Tak, to palindrom";
        }
        else{
            std::cout << "Nie, to nie palindrom";
        }
    }

    return 0;
}