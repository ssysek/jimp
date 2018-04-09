//
// Created by Sysek on 2018-04-09.
//


#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H

#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>

namespace pool {
    class TextPool {
    public:
        TextPool();
        TextPool(const std::initializer_list<std::string> &elements);
        std::experimental::string_view Intern(const std::string &str);
        TextPool(TextPool &&tp);
        TextPool &operator=(TextPool &&tp);
        TextPool(const TextPool &) = delete;
        TextPool &operator=(const TextPool &) = delete;
        ~TextPool();
        size_t StoredStringCount() const;
    private:
        std::set<std::string> pole_;
    };
}




#endif //JIMP_EXERCISES_TEXTPOOL_H
