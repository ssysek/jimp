//
// Created by Jan on 04.06.2018.
//

#ifndef JIMP_EXERCISES_SEQUENTIALGENERATOR_H
#define JIMP_EXERCISES_SEQUENTIALGENERATOR_H

template <class TYP_ID, class TYP_PROSTY>
class SequentialIdGenerator {
public:
    SequentialIdGenerator();
    SequentialIdGenerator(TYP_PROSTY licznik_);
    ~SequentialIdGenerator();
    TYP_ID NextValue();

private:
    bool head;
    TYP_PROSTY licznik;
};


#endif //JIMP_EXERCISES_SEQUENTIALGENERATOR_H
