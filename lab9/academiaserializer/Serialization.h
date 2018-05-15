//
// Created by syskmaci on 08.05.18.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include <string>
#include <sstream>
#include <vector>
#include <functional>
#include <experimental/optional>

namespace academia {
    class Serializer;
    class Serializable {
    public:
        Serializable() {};
        virtual void Serialize(Serializer* serializer) const =0;
    };


    class Room : public Serializable{
    public:
        enum class Type {
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM
        };

        Room() { };
        Room(int id, std::string name, Type type);
        int Id() { return id_; };
        void Serialize(Serializer* serializer) const override ;
        std::string TypeToString(Room::Type type) const;

    private:
        int id_;
        std::string name_;
        Type type_;

    };

    class Building:public Serializable {
    public:
        Building() { };
        Building(int id, const std::string &name, const std::vector<Room> &rooms);
        void Serialize(Serializer* serializer) const override ;
        int Id() const { return id_; }

    private:
        int id_;
        std::string name_;
        std::vector<Room> rooms_;
    };


    class Serializer {
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

    protected:
        std::ostream* out_;
    };

    class XmlSerializer: public Serializer {
    public:
        XmlSerializer(std::stringstream *out):Serializer(out){}
        void IntegerField(const std::string &field_name, int value) override;
        void DoubleField(const std::string &field_name, double value) override;
        void StringField(const std::string &field_name, const std::string &value) override;
        void BooleanField(const std::string &field_name, bool value) override;
        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;
        void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override;
        void Header(const std::string &object_name) override;
        void Footer(const std::string &object_name) override;
    };
    class JsonSerializer: public Serializer {
    public:
        JsonSerializer(std::stringstream *out):Serializer(out){}
        void IntegerField(const std::string &field_name, int value) override;
        void DoubleField(const std::string &field_name, double value) override;
        void StringField(const std::string &field_name, const std::string &value) override;
        void BooleanField(const std::string &field_name, bool value) override;
        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;
        void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override;
        void Header(const std::string &object_name) override;
        void Footer(const std::string &object_name) override;

    private:
        bool needOpen = false;
    };
    class BuildingRepository {
    public:
        BuildingRepository() { };
        BuildingRepository(const std::initializer_list<Building> buildings);
        void StoreAll(Serializer *serial) const;
        void Add(const Building &building);
        std::experimental::optional<Building> operator[](int id) const;

    private:
        std::vector<Building> buildings_;
    };
}


#endif //JIMP_EXERCISES_SERIALIZATION_H