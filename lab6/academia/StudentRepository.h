//
// Created by syskmaci on 10.04.18.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORY_H
#define JIMP_EXERCISES_STUDENTREPOSITORY_H

#include <iostream>
#include <string>
#include <vector>

namespace academia{

    class StudyYear{
    public:
        StudyYear();
        StudyYear(int study_year);
        ~StudyYear();
        void SetYear(int study_year);

        StudyYear &operator++();
        StudyYear &operator--();

        bool operator==(StudyYear another_study_year) const;
        bool operator>(StudyYear another_study_year) const;
        bool operator<(StudyYear another_study_year) const;

        operator int() const;
    private:
        int study_year;
    };

    class Student{
    public:
        Student();
        Student(std::string id_, std::string Name_, std::string Surname_, std::string program_, int year_);
        ~Student();


    };
}


#endif //JIMP_EXERCISES_STUDENTREPOSITORY_H
