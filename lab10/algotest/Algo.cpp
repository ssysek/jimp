//
// Created by zasadjan on 15.05.18.
//

#include "Algo.h"


void Algo::SortInPlace(std::vector<int> *v) {
    std::sort(v->begin(), v->end());
}

void SortByFirstInPlace(std::vector<std::pair<int,int>> *v){

    std::vector<std::pair<int,int>> vc;
    std::copy(v->begin(),v->end(),vc.begin());
    std::sort(v->begin(), v->end(), [](auto &left, auto &right){
        return left.first < right.first;
    });

}

void SortBySecondInPlace(std::vector<std::pair<int,int>> *v){

    std::vector<std::pair<int,int>> vc;
    std::copy(v->begin(),v->end(),vc.begin());
    std::sort(v->begin(), v->end(), [](auto &left, auto &right){
        return left.second < right.second;
    });

}


void SortByThirdInPlace(std::vector<std::tuple<int,int,int>> *v){

    std::vector<std::tuple<int,int,int>> vc;
    std::copy(v->begin(),v->end(),vc.begin());
    std::sort(v->begin(), v->end(), [](auto &left, auto &right){
        return std::get<2>(left) < std::get<2>(right);
    });
}
