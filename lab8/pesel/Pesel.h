//
// Created by syskmaci on 24.04.18.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H

#include <string>
#include <iostream>

namespace academia{
class Pesel {
public:
    Pesel(std::string pesel_);
    ~Pesel() {}
    void CheckPesel(std::string pesel);
    std::string NrPesel;
};

class InvalidPeselLength{

};

class InvalidPeselCharacter{

};

class InvalidPeselChecksum : public AcademiaDataValidationError{

};
  class AcademiaDataValidationError : public invalid_argument{

  };
};
#endif //JIMP_EXERCISES_PESEL_H
