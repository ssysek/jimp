//
// Created by mwypych on 01.06.17.
//

//1 do 4999


#include <gtest/gtest.h>
#include "ArabicRoman.h"


TEST(arabic_to_roman,Arabic1IsRomanI){
    EXPECT_EQ("I",ArabicToRoman(1));
}