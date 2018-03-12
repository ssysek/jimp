//
// Created by Jan on 05.03.2018.
//
#include <iostream>
#include <string>
#include <algorithm>
#include "Palindrome.h"

bool IsPalindrome(std::string str){
    bool czypal= true;
    int dl=str.size()-1;
    int licznik=0;
    while(licznik<dl&&czypal==true){
        if(str[licznik]!=str[dl]){
            czypal=false;

        }
        dl--;
        licznik++;
    }
    return czypal;

};