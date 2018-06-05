//
// Created by mwypych on 01.06.17.
//

//1 do 4999


#include <gtest/gtest.h>
#include "ArabicRoman.h"


TEST(arabic_to_roman,Arabic1IsRomanI){
    EXPECT_EQ("I",ArabicToRoman(1));
}

TEST(arabic_to_roman,Arabic3999IsRomanMMMCMXCIX){
    EXPECT_EQ("MMMCMXCIX",ArabicToRoman(3999));
}

TEST(arabic_to_roman,Arabic2137IsRomanMMCXXXVII){
    EXPECT_EQ("MMCXXXVII",ArabicToRoman(2137));
}

TEST(arabic_to_roman,Arabic1488IsRomanMCDLXXXVIII){
    EXPECT_EQ("MCDLXXXVIII",ArabicToRoman(1488));
}

TEST(arabic_to_roman,Arabic420IsRomanCDXX){
    EXPECT_EQ("CDXX",ArabicToRoman(420));
}