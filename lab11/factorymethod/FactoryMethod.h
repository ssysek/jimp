//
// Created by syskmaci on 22.05.18.
//

#ifndef JIMP_EXERCISES_FACTORYMETHOD_H
#define JIMP_EXERCISES_FACTORYMETHOD_H

#include <string>

namespace factoryMethod {
    template <typename T>
    T Create();

    class MyType {
    public:
        std::string SayHello();;
    };
}


#endif //JIMP_EXERCISES_FACTORYMETHOD_H
