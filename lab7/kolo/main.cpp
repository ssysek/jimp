//
// Created by zasadjan on 17.04.18.
//

#include "Kula.h"
#include "Kolo.h"
#include <iostream>

using namespace std;

int main(){
    Kolo a=Kolo(0,0,2);
    cout << a.pole() <<endl;
    Kula b=Kula(0,0,0,2);
    cout << b.pole();
}