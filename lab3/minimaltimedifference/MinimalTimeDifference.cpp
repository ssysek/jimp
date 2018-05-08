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

    int ga=ToMinutes(times[0]);
    int gb=ToMinutes(times[1]);
    if(ga==0){
        ga=1440;
    }
    if(gb==0){
        gb=1440;
    }

    if(ga>gb){
        return ga-gb;
    }
    else{
        return gb-ga;
    }
    /*
    for (auto time:times){
        unsigned int tmp = ToMinutes(time);
        minutes.emplace_back(tmp);
    }

    sort(minutes.begin(), minutes.end());
    unsigned int diff;



    for( int k = 0 ; k<minutes.size() - 1; k++){
        diff = minutes[k+1] - minutes[k];
        if(diff>720){
            minutes[k+1]=
        }
        if (diff < min){
            min = diff;}
    }
    */
    //return min;
}
