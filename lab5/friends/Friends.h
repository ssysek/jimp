//
// Created by zasadjan on 27.03.18.
//

#ifndef JIMP_EXERCISES_FRIENDS_H
#define JIMP_EXERCISES_FRIENDS_H


class Rodzic{
    string Imie;
    string Nazwisko;
    int Wiek;

     friend class Dziecko;

};

class Dziecko{
    string Imie;
    string Nazwisko;
    int Wiek;
    string Szkoła;

};


#endif //JIMP_EXERCISES_FRIENDS_H
