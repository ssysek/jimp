//
// Created by zasadjan on 22.05.18.
//

#include "Sum.h"

int main(){
    int a=2.0;
    int b=3.0;
    std::complex<double> c=4.0;
    std::complex<double> d=5.0;

    int *e=new int(6);

    std::cout << "2+4= " <<SumOfTwo(a,c)<<std::endl;
    std::cout << "3+5= " <<SumOfTwo(b,d)<<std::endl;

    std::shared_ptr<int> a2=std::make_shared<int>(a);
    std::cout << Value(a2)<< std::endl;
    std::cout << Value(e)<< std::endl;

}