//
// Created by Sysek on 2018-03-24.
//

#include <sstream>
#include <map>
#include "SimpleJson.h"

namespace nets{
    JsonValue::JsonValue(bool tmp) {
        JVbool_ = tmp;
    }

    JsonValue::JsonValue(int tmp) {
        JVint_ = tmp;
    }

    JsonValue::JsonValue(double tmp) {
        JVdouble_ = tmp;
    }

    JsonValue::JsonValue(std::string tmp) {
        JVstring_ = tmp;
    }

    JsonValue::JsonValue(std::vector<JsonValue> tmp) {
        JVvector_ = tmp;
    }

    JsonValue::JsonValue(std::map<std::string, JsonValue> tmp) {
        JVmap_ = tmp;
    }



    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const {
        auto it = JVmap_.find(name);
        if (it != JVmap_.end())
            return it->second;
    }
    std::string JsonValue::ToString() const {
        std::stringstream wynik;
        if (JVint_ != 0)
            wynik << JVint_;
        else if (JVdouble_ != 0)
            wynik << JVdouble_;
        else if (!JVstring_.empty())
            wynik << JVstring_;


        else if (JVvector_.size() > 0) {
            wynik << "[";
            for (int i = 0; i < JVvector_.size(); i++) {
                wynik <<JVvector_[i].ToString();
                if (i != JVvector_.size() - 1) {
                    wynik << ", ";
                }
            }
            wynik << "]";
        }

        else if (JVmap_.size() > 0) {
            wynik << "{";
            int i = 0;
            size_t mapSize = JVmap_.size();
            for (auto const &e: JVmap_) {
                wynik << e.first << ": " << e.second.ToString();
                i++;
                if (i < mapSize)
                    wynik << ", ";
            }
            wynik << "}";
        } else {
            if (JVbool_)
                wynik << "true";
            else
                wynik << "false";
        }
        return wynik.str();
    }

}