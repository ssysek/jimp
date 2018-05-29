//
// Created by zasadjan on 22.05.18.
//



#ifndef JIMP_EXERCISES_SUM_H
#define JIMP_EXERCISES_SUM_H

#include <iostream>
#include <complex>
#include <memory>

template<class X,class Y>
auto SumOfTwo(const X first, const Y second){
    std::complex<double> a=first;
    std::complex<double> b=second;
    return a+b;

};

template<class Z>
auto Value(std::shared_ptr<Z> obj){
    return *obj;

}




#endif //JIMP_EXERCISES_SUM_H
