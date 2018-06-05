//
// Created by mwypych on 01.06.17.
//

#include <gtest/gtest.h>
#include "ArabicRoman.h"

TEST(roman_to_arabic, RomanIIsArabic1){

    EXPECT_EQ(1, RomanToArabic("I"));

}