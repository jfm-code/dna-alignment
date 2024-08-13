// Copyright 2024 Jessica Vu

#include <iostream>
#include "EDistance.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(testMin3) {
    EDistance distance("AACAGTTACC", "TAAGGTCA");
    int a = 25;
    int b = 23502;
    int c = 14;
    BOOST_REQUIRE_EQUAL(distance.min3(a, b, c), 14);
}

BOOST_AUTO_TEST_CASE(testPenalty) {
    EDistance distance("AACAGTTACC", "TAAGGTCA");
    BOOST_REQUIRE_EQUAL(distance.penalty('t', 'T'), 1);
}

BOOST_AUTO_TEST_CASE(testOptDistance) {
    EDistance distance("AACAGTTACC", "TAAGGTCA");
    int output = distance.optDistance();
    BOOST_REQUIRE_EQUAL(output, 7);
}

BOOST_AUTO_TEST_CASE(testAlignment) {
    EDistance distance("atattat", "tattata");
    distance.optDistance();
    std::string output = distance.alignment();
    BOOST_REQUIRE_EQUAL(output, "a - 2\nt t 0\na a 0\nt t 0\nt t 0\na a 0\nt t 0\n- a 2\n");
}
