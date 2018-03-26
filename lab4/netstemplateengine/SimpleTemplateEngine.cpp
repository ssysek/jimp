//
// Created by Jan on 26.03.2018.
//
#include "SimpleTemplateEngine.h"

using namespace std;

::nets::View::View(string szablon) : template_str(szablon) {}

string nets::View::tenszablon() const {
    return this->template_str;
}
string nets::View::Render(const unordered_map <string, string> &model) const {

    stringstream nowystring;
    smatch wynik;
    string stringszablon = this->tenszablon();
    regex wzor ("\\{\\{([\\d\\w_]*)\\}\\}");

    while (regex_search(stringszablon, wynik, wzor)) {
        string zmiana = "";

        for (auto element : model) {
            if (wynik[1] == element.first) {
                zmiana = element.second;
            }
        }

        nowystring << wynik.prefix() << zmiana;
        stringszablon = wynik.suffix();


    nowystring << stringszablon;
    return nowystring.str();
}}
