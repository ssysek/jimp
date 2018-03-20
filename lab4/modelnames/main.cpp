//
// Created by syskmaci on 20.03.18.
//

#include <iostream>
#include <string>
#include "Name.h"

int main(){
    Name ja ("Maciej Tadeusz Maksymilian Syska");
    ja.print();
    std::cout<<std::endl;
    std::cout<<ja.FirstName()<<std::endl;
    std::cout<<ja.SecondName()<<std::endl;
    std::cout<<ja.ThirdName()<<std::endl;
    std::cout<<ja.Surname()<<std::endl;

    return 0;
}