//
// Created by Jan on 04.06.2018.
//

#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H


#include <chrono>
#include <iostream>
#include <utility>



#include <chrono>
#include <iostream>
#include <utility>

namespace profiling {

    template<class T>
    auto TimeRecorder(T obj){
        auto start = std::chrono::high_resolution_clock::now();
        auto wart = (obj)();
        auto stop = std::chrono::high_resolution_clock::now();
        double czas = std::chrono::duration<double, std::milli>(stop-start).count();
        return std::make_pair(wart, czas);
    };

}


#endif //JIMP_EXERCISES_TIMERECORDER_H
