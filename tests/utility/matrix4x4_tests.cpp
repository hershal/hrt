#include <boost/test/unit_test.hpp>

#include <limits>

#include "utility/matrix4x4.hpp"
#include "utility/utility_functions.hpp"

#include <iostream>

BOOST_AUTO_TEST_SUITE(matrix4x4_tests)

BOOST_AUTO_TEST_CASE(eye_naive) {

    float m[4][4];
    hrt::matrix4x4::eye(m);

    for (int i=0; i<4; ++i) {
        for (int j=0; j<4; ++j) {
            if (i==j) {
                BOOST_CHECK(absolute_error(m[i][j], 1.f) < machine_epsilon);
            } else {
                BOOST_CHECK(absolute_error(m[i][j], 0.f) < machine_epsilon);
            }
        }
    }
}

BOOST_AUTO_TEST_SUITE_END()
