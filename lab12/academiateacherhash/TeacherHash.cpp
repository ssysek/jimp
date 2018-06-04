//
// Created by Jan on 04.06.2018.
//

#include "TeacherHash.h"

//int Teacher::Id(){
//    return id.tid;
//}
//
//std::string Teacher::Name(){
//    return name;
//}
//
//std::string Teacher::Department() {
//    return department;
//
//}

size_t academia::TeacherHash::operator()() const{
    size_t hash_name=std::hash<std::string>{}(teacher.name);
    size_t hash_dept=std::hash<std::string>{}(teacher.department);
    size_t hash_id=std::hash<int>{}(teacher.id.tid);
    return hash_name+hash_dept+hash_id;
};