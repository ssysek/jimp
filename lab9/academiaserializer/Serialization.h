//
// Created by syskmaci on 08.05.18.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include <string>
#include <sstream>
#include <vector>


namespace academia{

    class Serializer;
    class Serializable {
    public:
        Serializable() {};
        virtual void Serialize(Serializer* serializer) const =0;
    };

    class Room:Serializable{
    public:
        enum class Type {
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM
        };
        Room() { };
        Room(int id, std::string name, Type type);
    };
}


#endif //JIMP_EXERCISES_SERIALIZATION_H
