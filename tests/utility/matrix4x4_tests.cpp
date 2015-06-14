#include <boost/test/unit_test.hpp>

#include <limits>

#include "utility/matrix4x4.hpp"
#include "utility/utility_functions.hpp"

#include <iostream>

BOOST_AUTO_TEST_SUITE(matrix4x4_tests)

void check_eye(float m[4][4]) {
    for (int i=0; i<4; ++i) {
        for (int j=0; j<4; ++j) {
            if (i==j) {
                BOOST_REQUIRE(approximately_equal(m[i][j], 1.f));
            } else {
                BOOST_REQUIRE(approximately_equal(m[i][j], 0.f));
            }
        }
    }
}

void check_zero(float m[4][4]) {
    for (int i=0; i<4; ++i) {
        for (int j=0; j<4; ++j) {
            BOOST_REQUIRE(approximately_equal(m[i][j], 0.f));
        }
    }
}

/* check if \m is approximately equal to \r */
void check_matrix(float m[4][4], float r[4][4]) {
    for (int i=0; i<4; ++i) {
        for (int j=0; j<4; ++j) {
            BOOST_REQUIRE(approximately_equal(m[i][j], r[i][j]));
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

    for(std::size_t i=0; i<4; ++i) {
        for(std::size_t j=0; j<4; ++j) {
            for(std::size_t k=0; k<4; ++k) {
                for(std::size_t l=0; l<4; ++l) {
                    if (i==j || k==l) { continue; }
                    if ((i == k) && (j == l)) {
                        BOOST_CHECK(approximately_equal(hrt::matrix4x4::_det2x2(m, i, j, k, l), 1.f));
                    } else if ((i == l) && (j == k)) {
                        BOOST_CHECK(approximately_equal(hrt::matrix4x4::_det2x2(m, i, j, k, l), -1.f));
                    } else {
                        BOOST_CHECK(approximately_equal(hrt::matrix4x4::_det2x2(m, i, j, k, l), 0.f));
                    }
                }
            }
        }
    }
}

BOOST_AUTO_TEST_CASE(det2x2_directed) {

    float m[4][4] = {{2,  3,  5,  7},
                     {11, 13, 17, 19},
                     {23, 29, 31, 37},
                     {41, 43, 47, 53}};

    BOOST_CHECK(approximately_equal(hrt::matrix4x4::_det2x2(m, 0, 1, 0, 1), -7.f));
    BOOST_CHECK(approximately_equal(hrt::matrix4x4::_det2x2(m, 0, 1, 1, 2), -14.f));
    BOOST_CHECK(approximately_equal(hrt::matrix4x4::_det2x2(m, 0, 1, 2, 3), -24.f));

    BOOST_CHECK(approximately_equal(hrt::matrix4x4::_det2x2(m, 1, 2, 0, 1), 20.f));
    BOOST_CHECK(approximately_equal(hrt::matrix4x4::_det2x2(m, 1, 2, 1, 2), -90.f));
    BOOST_CHECK(approximately_equal(hrt::matrix4x4::_det2x2(m, 1, 2, 2, 3), 40.f));

    BOOST_CHECK(approximately_equal(hrt::matrix4x4::_det2x2(m, 2, 3, 0, 1), -200.f));
    BOOST_CHECK(approximately_equal(hrt::matrix4x4::_det2x2(m, 2, 3, 1, 2), 30.f));
    BOOST_CHECK(approximately_equal(hrt::matrix4x4::_det2x2(m, 2, 3, 2, 3), -96.f));

    float f;
    for(std::size_t i=0; i<4; ++i) {
        for(std::size_t j=0; j<4; ++j) {
            for(std::size_t k=0; k<4; ++k) {
                for(std::size_t l=0; l<4; ++l) {
                    f = m[i][k]*m[j][l] - m[i][l]*m[j][k];
                    BOOST_CHECK(approximately_equal(hrt::matrix4x4::_det2x2(m, i, j, k, l), f));
                }
            }
        }
    }
}

BOOST_AUTO_TEST_CASE(det3x3_basic) {

    float mat[4][4];
    hrt::matrix4x4::eye(mat);

    BOOST_CHECK(approximately_equal(hrt::matrix4x4::_det3x3(mat, 0, 1, 2, 0, 1, 2), 1.f));
    BOOST_CHECK(approximately_equal(hrt::matrix4x4::_det3x3(mat, 1, 2, 3, 1, 2, 3), 1.f));

    BOOST_CHECK(approximately_equal(hrt::matrix4x4::_det3x3(mat, 0, 1, 2, 1, 2, 3), 0.f));
    BOOST_CHECK(approximately_equal(hrt::matrix4x4::_det3x3(mat, 1, 2, 3, 0, 1, 2), 0.f));
}

BOOST_AUTO_TEST_CASE(det3x3_directed) {

    float mat[4][4] = {{2,  3,  5,  7},
                     {11, 13, 17, 19},
                     {23, 29, 31, 37},
                     {41, 43, 47, 53}};

    BOOST_CHECK(approximately_equal(hrt::matrix4x4::_det3x3(mat, 0, 1, 2, 0, 1, 2), 70.f));
    BOOST_CHECK(approximately_equal(hrt::matrix4x4::_det3x3(mat, 0, 1, 2, 1, 2, 3), -160.f));

    BOOST_CHECK(approximately_equal(hrt::matrix4x4::_det3x3(mat, 1, 2, 3, 0, 1, 2), -600.f));
    BOOST_CHECK(approximately_equal(hrt::matrix4x4::_det3x3(mat, 1, 2, 3, 1, 2, 3), 240.f));

    float a, b, c, d, e, f, g, h, ii, x;
       for(std::size_t i=0; i<4; ++i) {
        for(std::size_t j=0; j<4; ++j) {
            for(std::size_t k=0; k<4; ++k) {
                for(std::size_t l=0; l<4; ++l) {
                    for(std::size_t m=0; m<4; ++m) {
                        for(std::size_t n=0; n<4; ++n) {
                            a = mat[i][l];
                            b = mat[i][m];
                            c = mat[i][n];
                            d = mat[j][l];
                            e = mat[j][m];
                            f = mat[j][n];
                            g = mat[k][l];
                            h = mat[k][m];
                            ii = mat[k][n];
                            x = a*e*ii + b*f*g + c*d*h - c*e*g - b*d*ii - a*f*h;
                            BOOST_CHECK(approximately_equal(hrt::matrix4x4::_det3x3(mat, i, j, k, l, m, n), x));
                        }
                    }
                }
            }
        }
    }
}

BOOST_AUTO_TEST_CASE(det4x4_basic) {

    float m[4][4];
    hrt::matrix4x4::eye(m);

    BOOST_CHECK(approximately_equal(hrt::matrix4x4::det(m), 1.f));
}

BOOST_AUTO_TEST_CASE(det4x4_directed) {

    float m[4][4] = {{2,  3,  5,  7},
                     {11, 13, 17, 19},
                     {23, 29, 31, 37},
                     {41, 43, 47, 53}};

    BOOST_CHECK(approximately_equal(hrt::matrix4x4::det(m), 880.f));
}

BOOST_AUTO_TEST_CASE(inverse_0) {

    float m[4][4] = {{1, 0, 0, 1},
                     {0, 2, 1, 2},
                     {2, 1, 0, 1},
                     {2, 0, 1, 4}};
    float mi[4][4];

    float mi_ref[4][4] = {{-2,  -1.f/2,  1,   1.f/2},
                          {1,   1.f/2,   0,   -1.f/2},
                          {-8,  -1,      2,   2},
                          {3,   1.f/2,   -1,  -1.f/2}};

    hrt::matrix4x4::inverse(m, mi);
    check_matrix(mi, mi_ref);
}

BOOST_AUTO_TEST_CASE(inverse_1) {

    float m[4][4] = {{2,  3,  5,  7},
                     {11, 13, 17, 19},
                     {23, 29, 31, 37},
                     {41, 43, 47, 53}};
    float mi[4][4];

    float mi_ref[4][4] = {{3.f/11,    -12.f/55,   -1.f/5,   2.f/11},
                          {-5.f/11,   -2.f/55,    3.f/10,   -3.f/22},
                          {-13.f/22,  307.f/440,  -1.f/10,  -9.f/88},
                          {15.f/22,   -37.f/88,   0,        7.f/88}};

    hrt::matrix4x4::inverse(m, mi);
    check_matrix(mi, mi_ref);
}

BOOST_AUTO_TEST_SUITE_END()
