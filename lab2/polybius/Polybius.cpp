//
// Created by Jan on 12.03.2018.
//
#include <iostream>
#include <string>
#include "Polybius.h"

using namespace std;

string change(string mg)
{
    string changed="";
    char tmp;
    for (int i=0;i<mg.length();i++)
    {
        tmp=(char)(toupper(mg[i]));
        switch(tmp)
        {
            case 'J':
                changed+='I';
                break;
            case ' ':
                break;
            default:
                changed+=tmp;
                break;
        }
    }

    return changed;
}
string change2(string mg){
    string changed="";
    char tmp;
    for (int i=0;i<mg.length();i++)
    {
        tmp=(char)(tolower(mg[i]));
        changed+=tmp;

    }

    return changed;
}


std::string PolybiusCrypt(std::string message){
    message=change(message);
    string wyn="";
    char literki[5][5]={{'A','B','C','D','E'},{'F','G','H','I','K'},{'L','M','N','O','P'},{'Q','R','S','T','U'},{'V','W','X','Y','Z'}};
    for(char& c : message){

        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(literki[i][j]==c){
                    wyn=wyn+to_string(i+1)+to_string(j+1);
                }
            }
        }
    }
    return change2(wyn);



}

std::string PolybiusDecrypt(std::string crypted){
    crypted=change(crypted);
    string wyn="";
    char literki[5][5]={{'A','B','C','D','E'},{'F','G','H','I','K'},{'L','M','N','O','P'},{'Q','R','S','T','U'},{'V','W','X','Y','Z'}};
    for(int i=0;i<(crypted.size());i=i+2){
        char ac=crypted[i];
        char bc=crypted[i+1];
        int a=(int)ac-48;
        int b=(int)bc-48;
        //cout <<a;
        //cout <<b;
        wyn=wyn+literki[a-1][b-1];
    }return change2(wyn);
}