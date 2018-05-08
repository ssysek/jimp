//
// Created by syskmaci on 10.04.18.
//

#include "StudentRepository.h"

namespace academia{
    StudyYear &StudyYear::operator++() {
        this->study_year ++;
        return *this;
    }

    StudyYear &StudyYear::operator--() {
        this->study_year --;
        return *this;
    }

    void StudyYear::SetYear(int study_year) {
        this->study_year=study_year;
    }
    StudyYear::~StudyYear(){
        //destruktor
    }
    StudyYear::StudyYear(int study_year) {
        this->study_year=1;
    }
    bool StudyYear::operator==(StudyYear another_study_year) const {
        return this->study_year==another_study_year.study_year;
    }
    bool StudyYear::operator>(StudyYear another_study_year) const {
        return this->study_year==another_study_year.study_year;
    }
    bool StudyYear::operator<(StudyYear another_study_year) const {
        return this->study_year==another_study_year.study_year;
    }

    bool CheckName(std::string Name_,std::string Surname_){
        std::regex r("/^[a-z ,.'-]+$/i");
        if(std::regex_match(Name_+" "+Surname_,r)){
            return true;
        }
        else{
            return false;
        }
    }

    bool CheckYear(int year_){
        if((2018-year_)>100 or (2018-year_)<10){
            return false;
        }
        else{
            return true;
        }
    }

    bool CheckCourse(std::string course_){
        if(course_=="informatyka" or course_=="ekonomia" or course_=="matematyka" or course_=="fizyka" or course_=="filozofia"){
            return true;
        }
        else{
            return false;
        }
    }

    void InvalidNameCharacter(){


            throw std::invalid_argument("Invalid name");

    }

    void InvalidAge(){

            throw std::invalid_argument("Invalid age");

    }

    void InvalidProgram(bool coursebool){

            throw std::invalid_argument("Invalid course");

    }

    //std::ostream &operator<<(std::ostream &s, const Student &v){
        //return s << "Stduent" << v.Surname_ << std::endl << "id: " <<v.id_ << std::endl << "program: " << v.program_;

   // }
}