//
// Created by syskmaci on 13.03.18.
//

#include "MinimalTimeDifference.h"
#include <vector>
#include <sstream>
#include <regex>
#include <cmath>
#include <string>

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