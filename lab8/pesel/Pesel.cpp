//
// Created by syskmaci on 24.04.18.
//

#include "Pesel.h"
namespace academia{

Pesel::Pesel(std::string pesel_){
    CheckPesel(pesel_);
    NrPesel=pesel_;
}

void Pesel::CheckPesel(std::string pesel) {
    int tab[10]={'9','7','3','1','9','7','3','1','9','7'};
    int CheckSum=0;
    if(pesel.length()!=11){
        throw InvalidPeselLength();
    } else {
        for(int i=0;i<10;i++) {
            int z = pesel[i] - '0';
            CheckSum=CheckSum + (z*tab[i]);
            if (pesel[i] < '0' || pesel[i] > '9')
                throw InvalidPeselCharacter();
        }
    }   int k = pesel[11] - '0';
        if((CheckSum%10)!=k)
            throw InvalidPeselChecksum();
    }
};