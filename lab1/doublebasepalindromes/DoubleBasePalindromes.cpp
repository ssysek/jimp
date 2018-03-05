//
// Created by Sysek on 2018-03-05.
//

#include <iostream>
#include <string>
#include <cstdint>
#include "DoubleBasePalindromes.h"

bool is_palindrome(std::string str){
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

uint64_t DoubleBasePalindromes(int max_value_exculsive){
    int i=0,tab[63];
    std::string dec="";

    std::string _str = std::to_string(max_value_exculsive);

    while(max_value_exculsive) //dopóki liczba będzie różna od zera
    {
        tab[i++]=max_value_exculsive%2;
        max_value_exculsive/=2;
    }
    for(int j=i-1;j>=0;j--)
        dec+=std::to_string(tab[j]);

    //std::cout<<is_palindrome(_str)<<std::endl;
    //std::cout<<dec<<std::endl;
    //std::cout<<is_palindrome(dec)<<std::endl;

    if(is_palindrome(_str) && is_palindrome(dec))
        return 1;

    return 0;

}