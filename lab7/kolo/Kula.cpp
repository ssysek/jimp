//
// Created by zasadjan on 17.04.18.
//
#include <math.h>
#include "Kula.h"
#include "Kolo.h"

double Kula::pole() {
    double pole=4*Kolo::pole();
    return pole;
}