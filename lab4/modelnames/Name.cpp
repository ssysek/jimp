//
// Created by syskmaci on 20.03.18.
//

#include "Name.h"

Name::Name(std::string nazwa) {
    std::string w1, w2, w3, w4;
    int czlony;
    for (int nr = 0; nr < nazwa.length(); nr++) {

        if (nazwa[nr] == ' ') {
            nazwa = nazwa.substr(nr + 1, nazwa.length() - 1);
            break;
        }
        w1 += nazwa[nr];
    }
    for (int nr = 0; nr < nazwa.length(); nr++) {

        if (nazwa[nr] == ' ') {
            nazwa = nazwa.substr(nr + 1, nazwa.length() - 1);
            break;
        }
        w2 += nazwa[nr];
    }
    for (int nr = 0; nr < nazwa.length(); nr++) {

        if (nazwa[nr] == ' ') {
            nazwa = nazwa.substr(nr + 1, nazwa.length() - 1);
            break;
        }
        w3 += nazwa[nr];
    }
    for (int nr = 0; nr < nazwa.length(); nr++) {

        if (nazwa[nr] == ' ') {
            nazwa = nazwa.substr(nr + 1, nazwa.length() - 1);
            break;
        }
        w4 += nazwa[nr];
    }


    if ((w4 == "") && (w3 == "")) {
        imie_ = w1;
        drugie_ = w3;
        trzecie_ = w4;
        nazwisko_ = w2;
        czlony=2;
    } else if ((w3 != "") && (w4 == "")) {
        imie_ = w1;
        drugie_ = w2;
        trzecie_ = w4;
        nazwisko_ = w3;
        czlony=3
    } else {
        imie_ = w1;
        drugie_ = w2;
        trzecie_ = w3;
        nazwisko_ = w4;
        czlony=4
    }
}

    void Name::print()
    {
        std::cout << imie_ << drugie_ << trzecie_ << nazwisko_;
    }
    std::string Name::FirstName() {
        return imie_;
    }

    std::string Name::SecondName() {
        return drugie_;
    }
    std::string Name::ThirdName()
    {
        return trzecie_;
    }
    std::string Name::Surname() {
        return nazwisko_;
    }
    std::string ToFullInitials(){
        if(czlony==2){
            return
        }
    }
