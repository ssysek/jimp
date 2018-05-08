//
// Created by zasadjan on 27.03.18.
//
#include "Xxx.h"

int main() {
    //Konstrukcja obiektu za pomocą domyślnego konstruktora
    //nieciekawe
    XXX old_xxx {};

    //Konstrukcja obiektu na podstawie już zaincjalizowanego
    XXX new_xxx {old_xxx};

    //znowu nieciekawy konstruktor domyślny...
    XXX another_xxx {};

    //tutaj przypisujemy stan obiektu jednego do drugiego
    //ale obydwa są już zaincjalizowane...
    another_xxx = new_xxx;

    //tutaj kończy się zakres funkcji main i wszystkie trzy obiekty tracą ważność
    //zostają wywołane więc destruktory
}

