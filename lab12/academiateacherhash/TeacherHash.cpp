//
// Created by Jan on 04.06.2018.
//

#include "TeacherHash.h"
using namespace std;
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
size_t academia::TeacherHash::operator()(const academia::Teacher &teacher) const {
    size_t h_n = std::hash<string>{}(teacher.name);
    size_t h_d = std::hash<string>{}(teacher.department);
    size_t h_id = std::hash<int>{}(teacher.id.tid);
    return h_d + h_id + h_n;
}

size_t academia::TeacherHash::operator()() const {
    size_t h_n = std::hash<string>{}(teacher.name);
    size_t h_d = std::hash<string>{}(teacher.department);
    size_t h_id = std::hash<int>{}(teacher.id.tid);
    return h_d + h_n + h_id;
}