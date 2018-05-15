//
// Created by zasadjan on 15.05.18.
//

#include "Algo.h"

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