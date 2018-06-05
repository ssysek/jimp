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

int value(char r)
{
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;

    return -1;
}

int RomanToArabic(std::string roman){

    int res = 0;
    for (int i=0; i<roman.length(); i++)
    {
        int s1 = value(roman[i]);
        if (i+1 < roman.length())
        {
            int s2 = value(roman[i+1]);
            if (s1 >= s2)
            {
                res = res + s1;
            }
            else
            {
                res = res + s2 - s1;
                i++;
            }
        }
        else
        {
            res = res + s1;
            i++;
        }
    }
    return res;
}

