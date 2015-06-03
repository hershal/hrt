#include <boost/test/unit_test.hpp>

#include <limits>

#include "utility/matrix4x4.hpp"
#include "utility/utility_functions.hpp"

BOOST_AUTO_TEST_SUITE(matrix4x4_tests)

bool approximately_equal(float actual, float expected) {
    return absolute_error(actual, expected) < machine_epsilon;
}

void check_eye(float m[4][4]) {
    for (int i=0; i<4; ++i) {
        for (int j=0; j<4; ++j) {
            if (i==j) {
                BOOST_CHECK(approximately_equal(m[i][j], 1.f));
            } else {
                BOOST_CHECK(approximately_equal(m[i][j], 0.f));
            }
        }
    }
}

void check_zero(float m[4][4]) {
    for (int i=0; i<4; ++i) {
        for (int j=0; j<4; ++j) {
            BOOST_CHECK(approximately_equal(m[i][j], 0.f));
        }
    }
}

BOOST_AUTO_TEST_CASE(eye) {

    float m[4][4];
    hrt::matrix4x4::eye(m);
    check_eye(m);
}

BOOST_AUTO_TEST_CASE(zero) {

    float m[4][4];
    hrt::matrix4x4::zero(m);
    check_zero(m);
}

BOOST_AUTO_TEST_CASE(copy_eye) {

    float m0[4][4];
    float m1[4][4];
    hrt::matrix4x4::eye(m0);
    hrt::matrix4x4::zero(m1);

    hrt::matrix4x4::copy(m0, m1);
    check_eye(m0);
    check_eye(m1);

    hrt::matrix4x4::zero(m0);
    hrt::matrix4x4::eye(m1);
    hrt::matrix4x4::copy(m0, m1);
    check_zero(m0);
    check_zero(m1);
}

BOOST_AUTO_TEST_SUITE_END()
