//
// Created by mwypych on 01.06.17.
//

#include <gtest/gtest.h>
#include "ArabicRoman.h"

TEST(roman_to_arabic, RomanIIsArabic1){

    EXPECT_EQ(1, RomanToArabic("I"));

}

TEST(roman_to_arabic, RomanMVIsArabic1005){

    EXPECT_EQ(1005, RomanToArabic("MV"));

}

TEST(roman_to_arabic, RomanXXXIsArabic30){

    EXPECT_EQ(30, RomanToArabic("XXX"));

}

TEST(roman_to_arabic, RomanMCMXLVIIIsArabic2018){

    EXPECT_EQ(2018, RomanToArabic("MCMXLVII"));

}