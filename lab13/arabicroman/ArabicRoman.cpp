//
// Created by zasadjan on 05.06.18.
//

#include "ArabicRoman.h"

std::string ArabicToRoman(int arabic){
    std::string w="";
    int tmp=arabic;
    while(tmp>=1000){
        tmp-=1000;
        w+="M";
    }
    while(tmp>=900){
        tmp-=900;
        w+="CM";
    }
    while(tmp>=500){
        tmp-=500;
        w+="D";
    }
    while(tmp>=400){
        tmp-=400;
        w+="CD";
    }
    while(tmp>=100){
        tmp-=100;
        w+="C";
    }
    while(tmp>=90){
        tmp-=90;
        w+="XC";
    }
    while(tmp>=50){
        tmp-=50;
        w+="L";
    }
    while(tmp>=40){
        tmp-=40;
        w+="XL";
    }
    while(tmp>=10){
        tmp-=10;
        w+="X";
    }
    while(tmp>=9){
        tmp-=9;
        w+="IX";
    }
    while(tmp>=5){
        tmp-=5;
        w+="V";
    }
    while(tmp>=4){
        tmp-=4;
        w+="IV";
    }
    while(tmp>=1){
        tmp-=1;
        w+="I";
    }
    return w;
}

int RomanToArabic(std::string roman){

    return 1;

}