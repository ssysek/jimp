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

    void SortBySecondInPlace(std::vector<std::pair<int, int>> *v);

    void SortByThirdInPlace(std::vector<std::tuple<int, int, int>> *v);
};

#endif //JIMP_EXERCISES_ALGO_H
