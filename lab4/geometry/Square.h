//
// Created by zasadjan on 20.03.18.
//

#ifndef JIMP_EXERCISES_SQUARE_H
#define JIMP_EXERCISES_SQUARE_H

#include "Point.h"
namespace geometry {
    class Square {

    public:
        Square();

        Square(Point a, Point b, Point c, Point d);

        ~Square();

        double Circumference();

        double Area();

    private:
        Point punkta, punktb, punktc, punktd;

    };
}

#endif //JIMP_EXERCISES_SQUARE_H
