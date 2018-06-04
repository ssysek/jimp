//
// Created by Jan on 04.06.2018.
//

#ifndef JIMP_EXERCISES_SEQUENTIALGENERATOR_H
#define JIMP_EXERCISES_SEQUENTIALGENERATOR_H

template <class TYP_ID, class TYP_PROSTY>
class SequentialIdGenerator {
public:
    SequentialIdGenerator() {
        head = true;
        licznik = 0;
    }
    SequentialIdGenerator(TYP_PROSTY licznik_){
        head=true;
        licznik=licznik_;
    };
    ~SequentialIdGenerator();
    TYP_ID NextValue(){

        if(!head){
            ++licznik;
        }
        head= false;
        return TYP_ID (licznik);

    };

private:
    bool head;
    TYP_PROSTY licznik;
};


#endif //JIMP_EXERCISES_SEQUENTIALGENERATOR_H
