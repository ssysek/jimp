//
// Created by zasadjan on 20.03.18.
//

//Definicja znajduje się w pliku Point.cpp
#include <cmath>
#include <ostream>
#include "Point.h"

using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;
using namespace std;

/* Aby wskazać, ze definicja funkcji dotyczy metody danej klasy
  stosujemy tzw. operator zasięgu - "::"
*/

//Specjalna inicjalizacja zmiennych. Zmienne są inicjowane
//nim zostanie wywołane ciało konstruktora
::geometry::Point::Point():x_(0),y_(0){

}

::geometry::Point::Point(double x, double y){

    x_ = x;
    y_ = y;
}

::geometry::Point::~Point(){

}

double ::geometry::Point::Distance(const Point &other) const{
    return sqrt(pow(x_-other.x_,2)+pow(y_-other.y_,2));
}
/*
void ::geometry::Point::ToString(ostream *out) const{
    (*out) << "(" << GetX() << ";" << GetY() << ")";
}
*/