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

    //std::ostream &operator<<(std::ostream &s, const Student &v){
        //return s << "Stduent" << v.Surname_ << std::endl << "id: " <<v.id_ << std::endl << "program: " << v.program_;

   // }
}