//
// Created by zasadjan on 17.04.18.
//

#ifndef JIMP_EXERCISES_KOLO_H
#define JIMP_EXERCISES_KOLO_H


class Kolo {

protected:
    double x,y,r;

public:
    Kolo(){};
    Kolo(double wx, double wy, double wr);
    ~Kolo(){};
    double pole();
};




#endif //JIMP_EXERCISES_KOLO_H
