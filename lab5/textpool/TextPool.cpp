//
// Created by Sysek on 2018-04-09.
//

#include <iostream>
#include "TextPool.h"


namespace pool {
    size_t TextPool::StoredStringCount() const {
        return pole_.size();
    }
    TextPool::TextPool() {}

    TextPool::TextPool(const std::initializer_list<std::string> &in) {
        for (auto s : in)
            Intern(s);
    }

    TextPool::~TextPool() {}
    TextPool::TextPool(TextPool &&tPoolMove) {
        std::swap(pole_, tPoolMove.pole_);
    }
    TextPool &TextPool::operator=(TextPool &&tPoolMove) {
        if (this == &tPoolMove) {
            return tPoolMove;
        }
        pole_.clear();
        std::swap(pole_, tPoolMove.pole_);
        return *this;
    }
    std::experimental::string_view TextPool::Intern(const std::string &str) {

        auto it = pole_.insert(str);

        return std::experimental::string_view(*(it.first));
    }

}