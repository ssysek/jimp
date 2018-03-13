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


unsigned int ToMinutes(std::string time_HH_MM){
    unsigned int minuty=0;
    if(time_HH_MM.size()==5){
        string godz=time_HH_MM.substr(0,2);
        int g = atoi(godz.c_str());
        string min=time_HH_MM.substr(3,2);
        int m= atoi(min.c_str());
        minuty=g*60+m;
    }
    else{
        string godz=time_HH_MM.substr(0,1);
        int g = atoi(godz.c_str());
        string min=time_HH_MM.substr(2,2);
        int m= atoi(min.c_str());
        minuty=g*60+m;
    }
    return minuty;

}
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
