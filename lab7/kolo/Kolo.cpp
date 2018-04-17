//
// Created by zasadjan on 17.04.18.
//
#include <math.h>
#include "Kolo.h"


Kolo::Kolo(double wx, double wy, double wr){
    x=wx;
    y=wy;
    r=wr;
}

double Kolo::pole(){
    return (M_PI*(this->r)*(this->r));
}