//
// Created by syskmaci on 22.05.18.
//

#include "FactoryMethod.h"

template<typename T>
T factoryMethod::Create() {
    return 0;
}

std::string factoryMethod::MyType::SayHello() {
    return "Hello";
}