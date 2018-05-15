//
// Created by zasadjan on 15.05.18.
//

#ifndef JIMP_EXERCISES_ALGO_H
#define JIMP_EXERCISES_ALGO_H

#include <vector>
#include <algorithm>
#include <tuple>


class Algo {
public:
    void SortInPlace(std::vector<int> *v);
    void SortByFirstInPlace(std::vector<std::pair<int, int>> *v);
    int Sum(const std::vector<int> &v);
    int Product(const std::vector<int> &v);
    int HowManyShortStrings(const std::vector<std::string> &v, int inclusive_short_length);
    void InitializeWith(int initial_value, std::vector<int> *v);
    bool Contains(const std::vector<int> &v, int element);
    void SortBySecondInPlace(std::vector<std::pair<int, int>> *v);

    void SortByThirdInPlace(std::vector<std::tuple<int, int, int>> *v);
};

#endif //JIMP_EXERCISES_ALGO_H
