//
// Created by Jan on 04.06.2018.
//

#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H


#include <chrono>
#include <iostream>
#include <utility>



#include <string>

using std::string;

namespace academia {
    class TeacherId {
    public:
        TeacherId(const int &id) { id_ = id; }

        TeacherId(const TeacherId &teacher) { id_ = teacher.id_; }

        operator int() const { return id_; };

        bool operator!=(const TeacherId &teacher) const { return teacher.id_ != id_; };

    private:
        int id_;
    };

    class Teacher {
    public:
        Teacher(const TeacherId &id, const string &name, const string &department) : id_(id), name_(name),
                                                                                     department_(department) {}

        bool operator==(const Teacher &teacher) const {
            return (id_ == teacher.id_
                    && name_ == teacher.name_
                    && department_ == teacher.department_);
        }

        bool operator!=(const Teacher &teacher) const { return !(*this == teacher); }

        const int Id() const { return id_; }

        const string Name() const { return name_; }

        const string Department() const { return department_; }

    private:
        TeacherId id_;
        string name_;
        string department_;
    };

    class TeacherHash {
    public:
        size_t operator()(const Teacher &teacher) const {
            size_t name = 0, department = 0;
            for (auto &character : teacher.Name()) name += character;

            for (auto &character :teacher.Department()) department += character;

            std::size_t h1 = std::hash<std::string>{}(teacher.Name());
            std::size_t h2 = std::hash<std::string>{}(teacher.Department());
            std::size_t h3 = std::hash<int>{}(teacher.Id());

            return h1 ^ h2 ^ h3;

        }
    };

}




#endif //JIMP_EXERCISES_TIMERECORDER_H
