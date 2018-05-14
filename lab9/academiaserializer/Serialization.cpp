//
// Created by syskmaci on 08.05.18.
//

#include "Serialization.h"

namespace academia {
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

    void Room::Serialize(Serializer *serializer) const {
        serializer->Header("room");
        serializer->IntegerField("id", id_);
        serializer->StringField("name", name_);
        serializer->StringField("type", TypeToString(type_));
        serializer->Footer("room");
    }


    Room::Room(int id, std::string name, Room::Type type) {
        id_ = id;
        name_ = name;
        type_ = type;
    }


    Serializer::Serializer(std::ostream *out) {
        out_ = out;
    }

    void Building::Serialize(Serializer *serializer) const {
        serializer->Header("building");
        serializer->IntegerField("id", id_);
        serializer->StringField("name", name_);
        std::vector<std::reference_wrapper<const Serializable>> wrapped(rooms_.begin(), rooms_.end());
        serializer->ArrayField("rooms", wrapped);
        serializer->Footer("building");
    }

    Building::Building(int id, const std::string &name, const std::vector<Room> &rooms) {
        id_ = id;
        name_ = name;
        rooms_ = rooms;
    }


    void XmlSerializer::IntegerField(const std::string &field_name, int value) {
        *out_ << "<" << field_name << ">" << value << "<\\" << field_name << ">";
    }


    void XmlSerializer::StringField(const std::string &field_name, const std::string &value) {
        *out_ << "<" << field_name << ">" << value << "<\\" << field_name << ">";
    }

    void XmlSerializer::DoubleField(const std::string &field_name, double value) {

    }

    void XmlSerializer::BooleanField(const std::string &field_name, bool value) {

    }

    void XmlSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {

    }

    void XmlSerializer::ArrayField(const std::string &field_name,
                                   const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
        *out_ << "<" << field_name << ">";
        for (const auto &v:value)
            v.get().Serialize(this);
        *out_ << "<\\" << field_name << ">";
    }

    void XmlSerializer::Header(const std::string &object_name) {
        *out_ << "<" << object_name << ">";
    }

    void XmlSerializer::Footer(const std::string &object_name) {
        *out_ << "<\\" << object_name << ">";
    }

    void JsonSerializer::IntegerField(const std::string &field_name, int value) {
        if (!needOpen)
            needOpen = true;
        else
            *out_ << ", ";
        *out_ << "\"" << field_name << "\": " << value << "";
    }


    void JsonSerializer::StringField(const std::string &field_name, const std::string &value) {
        if (!needOpen)
            needOpen = true;
        else
            *out_ << ", ";
        *out_ << "\"" << field_name << "\": \"" << value << "\"";
    }

    void JsonSerializer::DoubleField(const std::string &field_name, double value) {

    }

    void JsonSerializer::BooleanField(const std::string &field_name, bool value) {

    }

    void JsonSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {

    }

    void JsonSerializer::ArrayField(const std::string &field_name,
                                    const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
        if (!needOpen)
            needOpen = true;
        else
            *out_ << ", ";
        *out_ << "\"" << field_name << "\": [";
        int a = 0;
        for (const auto &n:value) {
            needOpen = false;
            n.get().Serialize(this);
            a++;

            if (a < value.size()) {
                *out_ << ", ";
            }
        }
        *out_ << "]";
    }

    void JsonSerializer::Header(const std::string &object_name) {
        *out_ << "{";
    }

    void JsonSerializer::Footer(const std::string &object_name) {
        *out_ << "}";
    }

    BuildingRepository::BuildingRepository(const std::initializer_list<Building> buildings) {
        for (Building building: buildings) {
            buildings_.emplace_back(building);
        }
    }

    void BuildingRepository::StoreAll(Serializer *serial) const {
        serial->Header("buildings_repository");
        std::vector<std::reference_wrapper<const Serializable>> wrap;
        for (auto building: buildings_)
            wrap.emplace_back(building);
        serial->ArrayField("buildings", wrap);
        serial->Footer("buildings_repository");
    }

    std::experimental::optional<Building> BuildingRepository::operator[](int id) const{
        for(auto build: buildings_){
            if(build.Id()==id) return std::experimental::make_optional(build);
        }
    };

    void BuildingRepository::Add(const Building &building) {
        buildings_.emplace_back(building);
    }
}