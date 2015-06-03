#include "utility/matrix4x4.hpp"
#include <boost/assert.hpp>

static float identity_matrix[4][4] =
    {{1.f, 0.f, 0.f, 0.f},
     {0.f, 1.f, 0.f, 0.f},
     {0.f, 0.f, 1.f, 0.f},
     {0.f, 0.f, 0.f, 1.f}};

auto hrt::matrix4x4::eye(float m[4][4]) -> void {
    memcpy(m, identity_matrix, 16*sizeof(float));
}

auto hrt::matrix4x4::zero(float m[4][4]) -> void {
    float *f = (float*)(m);
    for (uint8_t i=0; i<16; ++i) {
        f[i] = 0.f;
    }
}

auto hrt::matrix4x4::copy(float src[4][4], float dst[4][4]) -> void {
    memcpy(dst, src, 16*sizeof(float));
}

auto hrt::matrix4x4::_det2x2(float m[4][4], int m0, int m1) -> float {

    BOOST_ASSERT_MSG(m0 >= 0 && m0 <= 2, "2x2 submatrix row offset impossible in a 4x4 matrix");
    BOOST_ASSERT_MSG(m0 >= 0 && m1 <= 2, "2x2 submatrix col offset impossible in a 4x4 matrix");

    return m[m0][m1] * m[m0+1][m1+1] - m[m0][m1+1] * m[m0+1][m1];
}
