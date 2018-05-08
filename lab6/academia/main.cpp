//
// Created by syskmaci on 10.04.18.
//

#include <iostream>
#include "StudentRepository.h"

using namespace std;
using namespace academia;

int main(){
    cout<<"Podaj Imię"<<endl;
    string inputname="";
    getline(cin,inputname);
    cout<<"Podaj Nazwisko"<<endl;
    string inputsurname="";
    getline(cin,inputsurname);
    cout<<"Podaj rok urodzenia"<<endl;
    string inputyear="";
    getline(cin,inputyear);
    cout<<"Podaj Kurs"<<endl;
    string inputcourse="";
    getline(cin,inputcourse);
    cout<<"Podaj Id"<<endl;
    string inputid="";
    getline(cin,inputid);

    bool error=false;
    int inputyearint=stoi(inputyear);

    if(CheckName(inputname,inputsurname)==false){
        InvalidNameCharacter;
        error=true;
    }

    if(CheckYear(inputyearint)==false){
        InvalidAge;
        error=true;
    }

    if(CheckCourse(inputcourse)==false){
        InvalidProgram;
        error=true;
    }

    if(error==true){
        cout<<"Wykryto jeden lub więcej błędów, nie dodano studenta do bazy"<<endl;
    }
    else{
        Student nowy=Student(inputid,inputname,inputsurname,inputcourse,inputyearint,inputcourse);
    }



    return 0;
}