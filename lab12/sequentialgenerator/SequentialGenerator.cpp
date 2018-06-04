//
// Created by Jan on 04.06.2018.
//

#include "SequentialGenerator.h"

SequentialIdGenerator::SequentialIdGenerator(){
    head=true;
    licznik=0;
}

SequentialIdGenerator::SequentialIdGenerator(TYP_PROSTY licznik_){
    head=true;
    licznik=licznik_;
}

TYP_ID SequentialIdGenerator::NextValue() {

    if(!head){
        licznik++;
    }
    head= false;
    return TYP_ID (licznik);

}