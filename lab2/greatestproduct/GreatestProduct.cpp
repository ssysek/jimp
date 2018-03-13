//
// Created by zasadjan on 06.03.18.
//

#include <vector>
#include "GreatestProduct.h"

int GreatestProduct(const std::vector<int> &numbers, int k){

    std::vector<int> another_vector;
    //int max=0;
    int max2=0;
    for (int i=0;i<k;i++) {
        int max=0;

        for (int v : numbers) {
            if (v > max&&v<another_vector) {
                max = v;
            }
        }
        //for (int v : numbers) {
          //  if (v > max2 && v != max) {
         //       max2 = v;
         //   }
        //}
        another_vector.push_back(max);
    }


};