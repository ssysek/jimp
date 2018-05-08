//
// Created by syskmaci on 10.04.18.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORY_H
#define JIMP_EXERCISES_STUDENTREPOSITORY_H

#include <iostream>
#include <string>
#include <vector>
#include <regex>

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
        Student(std::string id_, std::string Name_, std::string Surname_, std::string program_, int year_, std::string course_);
        ~Student();
        bool CheckName(std::string Name_,std::string Surname_);
        bool CheckYear(int year_);
        bool CheckCourse(std::string course_);
        void InvalidNameCharacters(bool namebool);
        void InvalidAge(bool agebool);
        void InvalidProgram(bool coursebool);


    };
}


#endif //JIMP_EXERCISES_STUDENTREPOSITORY_H
