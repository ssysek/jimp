//
// Created by syskmaci on 08.05.18.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H


namespace academia{

    class Serializer;
    class Serializable {
    public:
        Serializable() {};
        virtual void Serialize(Serializer* serializer) const =0;
    };

    class Room:Serializable{
        enum class Type {
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM
        };
    };
}


#endif //JIMP_EXERCISES_SERIALIZATION_H
