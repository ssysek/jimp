//
// Created by syskmaci on 08.05.18.
//

#include "Serialization.h"

namespace academia {

    Serializer::Serializer(std::ostream *out) {
        out_ = out;
    }


    std::string Room::TypeToString(Room::Type type) const {
        switch (type) {
            case Room::Type::COMPUTER_LAB:
                return "COMPUTER_LAB";
            case Room::Type::LECTURE_HALL:
                return "LECTURE_HALL";
            case Room::Type::CLASSROOM:
                return "CLASSROOM";
        }
    }
