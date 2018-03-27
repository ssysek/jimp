//
// Created by Jan on 26.03.2018.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H

#include <string>
#include <unordered_map>
#include <iostream>
#include <regex>
#include <sstream>

namespace nets {
    class View {
    public:

        View (std::string szablon);
        std::string tenszablon() const;
        std::string Render(const std::unordered_map <std::string, std::string> &model) const;
    private:

        std::string template_str;
    };
}


#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
