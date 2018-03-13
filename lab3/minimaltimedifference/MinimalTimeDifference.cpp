//
// Created by syskmaci on 13.03.18.
//

#include "MinimalTimeDifference.h"
#include <vector>
#include <sstream>
#include <regex>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

unsigned int MinimalTimeDifference(std::vector<std::string> times){
    unsigned int min=1440;
    vector<unsigned int> minutes;

    for (auto time:times){
        unsigned int tmp = ToMinutes(time);
        minutes.emplace_back(tmp);
    }

    sort(minutes.begin(), minutes.end());

    for( int k = 0 ; k<minutes.size() - 1; k++){
        unsigned int diff = minutes[k] - minutes[k+1];
        if (diff < min)
            min = diff;
    }
    return min;
}
