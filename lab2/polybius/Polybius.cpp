//
// Created by Jan on 12.03.2018.
//
#include <iostream>
#include <string>
#include "Polybius.h"

using namespace std;



std::string PolybiusCrypt(std::string message){
    string wyn="";
    char literki[5][5]={{'A','B','C','D','E'},{'F','G','H','I','K'},{'L','M','N','O','P'},{'Q','R','S','T','U'},{'V','W','X','Y','Z'}};
    for(char& c : message){

        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(literki[i][j]==c){
                    wyn=wyn+to_string(i+1)+to_string(j+1)+" ";
                }
            }
        }
    }
    return wyn;



}

std::string PolybiusDecrypt(std::string crypted){



}