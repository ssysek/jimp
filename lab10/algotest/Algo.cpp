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

int Algo::Product(const std::vector<int> &v) {
    int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
    return product;
}

int Algo::Sum(const std::vector<int> &v){
    int sum = std::accumulate(v.begin(),v.end(),1);
    return sum;
}
/*int Algo::HowManyShortStrings(const std::vector<std::string> &v, int inclusive_short_length){
    int n=0;
    std::for_each(v.begin(),v.end(),);
}*/
void Algo::InitializeWith(int initial_value, std::vector<int> *v) {
    std::fill(v->begin(), v->end(), initial_value);
}
bool Algo::Contains(const std::vector<int> &v, int element){
    int tab[]={element};
   return std::search(v.begin(),v.end(),tab,tab+1)==v.end();

}