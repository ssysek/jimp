//
// Created by zasadjan on 20.03.18.
//

#include <iostream>

#include "Square.h"
#include "Point.h"

::geometry::Square::Square(): punkta(0,0),  punktb(0,0),  punktc(0,0),  punktd(0,0) {}

::geometry::Square::Square(Point a, Point b, Point c, Point d) {

    punkta=a;
    punktb=b;
    punktc=c;
    punktd=d;
}

::geometry::Square::~Square() {}

double ::geometry::Square::Circumference() {
    double bok1=punkta.Distance(punktc);
    double bok2=punktb.Distance(punktd);
    //double bok3=punktc.Distance(punktd);
    //double bok4=punktd.Distance(punkta);
    return 2*(bok1+bok2);

}

double ::geometry::Square::Area() {
    double bok1=punkta.Distance(punktc);
    double bok2=punktb.Distance(punktd);
    return bok1*bok2;

}