#include <boost/test/unit_test.hpp>

#include <limits>

#include "utility/matrix4x4.hpp"
#include "utility/utility_functions.hpp"

BOOST_AUTO_TEST_SUITE(matrix4x4_tests)

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

BOOST_AUTO_TEST_CASE(det2x2_basic) {

    float m[4][4];
    hrt::matrix4x4::eye(m);

    BOOST_CHECK(approximately_equal(hrt::matrix4x4::_det2x2(m, 0, 0), 1.f));
    BOOST_CHECK(approximately_equal(hrt::matrix4x4::_det2x2(m, 0, 1), 0.f));
    BOOST_CHECK(approximately_equal(hrt::matrix4x4::_det2x2(m, 0, 2), 0.f));

    BOOST_CHECK(approximately_equal(hrt::matrix4x4::_det2x2(m, 1, 0), 0.f));
    BOOST_CHECK(approximately_equal(hrt::matrix4x4::_det2x2(m, 1, 1), 1.f));
    BOOST_CHECK(approximately_equal(hrt::matrix4x4::_det2x2(m, 1, 2), 0.f));

    BOOST_CHECK(approximately_equal(hrt::matrix4x4::_det2x2(m, 2, 0), 0.f));
    BOOST_CHECK(approximately_equal(hrt::matrix4x4::_det2x2(m, 2, 1), 0.f));
    BOOST_CHECK(approximately_equal(hrt::matrix4x4::_det2x2(m, 2, 2), 1.f));
}

BOOST_AUTO_TEST_CASE(det2x2_directed) {

    float m[4][4] = {{2,  3,  5,  7},
                     {11, 13, 17, 19},
                     {23, 29, 31, 37},
                     {41, 43, 47, 53}};

    BOOST_CHECK(approximately_equal(hrt::matrix4x4::_det2x2(m, 0, 0), -7.f));
    BOOST_CHECK(approximately_equal(hrt::matrix4x4::_det2x2(m, 0, 1), -14.f));
    BOOST_CHECK(approximately_equal(hrt::matrix4x4::_det2x2(m, 0, 2), -24.f));

    BOOST_CHECK(approximately_equal(hrt::matrix4x4::_det2x2(m, 1, 0), 20.f));
    BOOST_CHECK(approximately_equal(hrt::matrix4x4::_det2x2(m, 1, 1), -90.f));
    BOOST_CHECK(approximately_equal(hrt::matrix4x4::_det2x2(m, 1, 2), 40.f));

    BOOST_CHECK(approximately_equal(hrt::matrix4x4::_det2x2(m, 2, 0), -200.f));
    BOOST_CHECK(approximately_equal(hrt::matrix4x4::_det2x2(m, 2, 1), 30.f));
    BOOST_CHECK(approximately_equal(hrt::matrix4x4::_det2x2(m, 2, 2), -96.f));
}

BOOST_AUTO_TEST_SUITE_END()
