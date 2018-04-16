//
// Created by Jan on 16.04.2018.
//

#ifndef JIMP_EXERCISES_COUNTS_H
#define JIMP_EXERCISES_COUNTS_H

namespace datastructures {

    class Counts {
    public:
        friend class WordCounter;

        Counts() {};

        ~Counts() {};

        Counts(int oo);

        Counts & operator++();

        bool operator<(Counts ignas) const ;

        bool operator>(Counts ignas) const ;

        bool operator==(Counts ignas) const ;

    private:
        int count;
    };

}
#endif //JIMP_EXERCISES_COUNTS_H