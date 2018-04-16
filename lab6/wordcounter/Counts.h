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
        Counts(int i);
        Counts & operator++();
        bool operator==(Counts zlicz) const ;
        bool operator>(Counts zlicz) const ;
        bool operator<(Counts zlicz) const ;

    private:

        int licznik;

    };

}
#endif //JIMP_EXERCISES_COUNTS_H