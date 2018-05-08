//
// Created by syskmaci on 08.05.18.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include <string>
#include <sstream>
#include <vector>


namespace academia{

    class Serializer{
    public:
        Serializer(std::ostream* out);
        Serializer() { };
        virtual void IntegerField(const std::string &field_name, int value) = 0;
        virtual void DoubleField(const std::string &field_name, double value) = 0;
        virtual void StringField(const std::string &field_name, const std::string &value) = 0;
        virtual void BooleanField(const std::string &field_name, bool value) = 0;
        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value) = 0;
        virtual void ArrayField(const std::string &field_name,
                                const std::vector<std::reference_wrapper<const academia::Serializable>> &value) = 0;
        virtual void Header(const std::string &object_name) = 0;
        virtual void Footer(const std::string &object_name) = 0;
    private:
        std::ostream* out_;
    };

    class JsonSerializer: public Serializer {
    public:
        JsonSerializer(std::stringstream *out) : Serializer(out) {}

        void IntegerField(const std::string &field_name, int value) override;

        void DoubleField(const std::string &field_name, double value) override;

        void StringField(const std::string &field_name, const std::string &value) override;

        void BooleanField(const std::string &field_name, bool value) override;

        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;

        void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override;

        void Header(const std::string &object_name) override;

        void Footer(const std::string &object_name) override;
    }

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
        std::string TypeToString(Room::Type type) const;
    };

    class Building:public Serializable {
    public:
        Building() { };

    }

}


#endif //JIMP_EXERCISES_SERIALIZATION_H
