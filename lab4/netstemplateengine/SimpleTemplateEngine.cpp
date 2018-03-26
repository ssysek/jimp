//
// Created by Jan on 26.03.2018.
//
#include "SimpleTemplateEngine.h"

::nets::View::View(std::string template_str) : template_str(template_str) {}

std::string nets::View::GetTemplateStr() const {
    return this->template_str;
}
std::string nets::View::Render(const std::unordered_map <std::string, std::string> &model) const {
    std::string template_str = this->GetTemplateStr();
    std::stringstream new_str;
    std::regex pattern ("\\{\\{([\\d\\w_]*)\\}\\}");
    std::smatch result;
    while (std::regex_search(template_str, result, pattern)) {
        std::string replacement = "";
        for (auto map_el : model) {
            if ( result[1] == map_el.first )
                replacement = map_el.second;
        }
        new_str << result.prefix() << replacement;
        template_str = result.suffix();
    }
    new_str << template_str;
    return new_str.str();
}