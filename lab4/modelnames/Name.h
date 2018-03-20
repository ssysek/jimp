//
// Created by syskmaci on 20.03.18.
//

#ifndef JIMP_EXERCISES_NAME_H
#define JIMP_EXERCISES_NAME_H

#include <iostream>
#include <string>

class Name{
public:
    Name(std::string nazwa);


    void print();
    std::string FirstName();
    std::string SecondName();
    std::string ThirdName();
    std::string Surname();
    std::string ToFullInitials();

private:
    std::string imie_;
    std::string drugie_;
    std::string trzecie_;
    std::string nazwisko_;
};


#endif //JIMP_EXERCISES_NAME_H
