
//
// Created by Sysek on 2018-03-24.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H

#include <experimental/optional>
#include <string>
#include <vector>
#include <map>

namespace nets {
    class JsonValue {
    public:
        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;
        std::string ToString() const;

        JsonValue(bool tmp);
        JsonValue(int tmp);
        JsonValue(double tmp);
        JsonValue(std::vector<JsonValue> tmp);
        JsonValue(std::string tmp);
        JsonValue(std::map<std::string, JsonValue> tmp);

    private:
        bool JVbool_= NULL;
        int JVint_ = 0;
        double JVdouble_ = 0;
        std::vector<JsonValue> JVvector_;
        std::string JVstring_ = "";
        std::map<std::string,JsonValue> JVmap_;
    };
}


#endif //JIMP_EXERCISES_SIMPLEJSON_H