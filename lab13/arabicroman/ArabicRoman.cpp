//
// Created by zasadjan on 05.06.18.
//

#include "ArabicRoman.h"

std::string ArabicToRoman(int arabic){
    std::string w="";
    while(arabic>=1000){
        arabic-=1000;
        w+="M";
    }
    while(arabic>=900){
        arabic-=900;
        w+="CM";
    }
    while(arabic>=500){
        arabic-=500;
        w+="D";
    }
    while(arabic>=400){
        arabic-=400;
        w+="CD";
    }
    while(arabic>=100){
        arabic-=100;
        w+="C";
    }
    while(arabic>=90){
        arabic-=90;
        w+="XC";
    }
    while(arabic>=50){
        arabic-=50;
        w+="L";
    }
    while(arabic>=40){
        arabic-=40;
        w+="XL";
    }
    while(arabic>=10){
        arabic-=10;
        w+="X";
    }
    while(arabic>=9){
        arabic-=9;
        w+="IX";
    }
    while(arabic>=5){
        arabic-=5;
        w+="V";
    }
    while(arabic>=4){
        arabic-=4;
        w+="IV";
    }
    while(arabic>=1){
        arabic-=1;
        w+="I";
    }
}

int RomanToArabic(std::string roman){

    return 1;

}