//
// Created by Jan on 04.06.2018.
//

#ifndef JIMP_EXERCISES_ACADEMIATEACHERHASH_H
#define JIMP_EXERCISES_ACADEMIATEACHERHASH_H

#include <string>
#include <functional>

class TeacherId{
public:
    TeacherId();
    TeacherId(int id_){
        tid=id_;
    };
    ~TeacherId();
    int Id();

    int tid;


};

class Teacher{
public:

    Teacher();
    Teacher(TeacherId id_, std::string name_, std::string department_){
        id=id_;
        name=name_;
        department=department_;
    };
    ~Teacher();
    int Id(){};
    std::string Name(){};
    std::string Department();
    TeacherId id;
    std::string name;
    std::string department;

    bool operator==(Teacher other) const{
        return (id.tid==other.id.tid && name==other.name && department==other.department);
    }

    bool operator!=(Teacher other) const{
        return (id.tid!=other.id.tid || name!=other.name || department!=other.department);
    }

};

class TeacherHash{
public:

    TeacherHash();
    TeacherHash(Teacher teacher_){
        teacher_.id.tid=teacher.id.tid;
        teacher_.name=teacher.name;
        teacher_.department=teacher.department;
    };
    ~TeacherHash();

    size_t operator()() const;
    Teacher teacher;

};



#endif //JIMP_EXERCISES_ACADEMIATEACHERHASH_H
