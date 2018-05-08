//
// Created by zasadjan on 17.04.18.
//

#ifndef JIMP_EXERCISES_KULA_H
#define JIMP_EXERCISES_KULA_H

#include "Kolo.h"

class Kula:Kolo{
protected:
    double z;

public:
    Kula(){};
    Kula(double x_, double y_, double z_, double r_):Kolo(x_, y_, r_){
        z=z_;
    }
    double pole();

};


#endif //JIMP_EXERCISES_KULA_H
