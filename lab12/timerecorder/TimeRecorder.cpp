//
// Created by Jan on 04.06.2018.
//

#include "TimeRecorder.h"

//
//    template<class T>
//    auto profiling::TimeRecorder(T obj) {
//        auto start = std::chrono::high_resolution_clock::now();
//
//        auto wart = obj();
//
//        auto stop = std::chrono::high_resolution_clock::now();
//
//        auto czas = stop - start;
//        return std::make_pair(wart, std::chrono::duration_cast<std::chrono::microseconds>(czas).count() * 1000);
//
//
//    }