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

auto hrt::matrix4x4::_det2x2(float m[4][4], int m0, int m1, int colskip, int rowskip) -> float {

    BOOST_ASSERT_MSG(m0 >= 0 && m0 <= 2, "2x2 submatrix row offset impossible in a 4x4 matrix");
    BOOST_ASSERT_MSG(m1 >= 0 && m1 <= 2, "2x2 submatrix col offset impossible in a 4x4 matrix");

    return m[m0][m1] * m[m0+1+rowskip][m1+1+colskip] - m[m0][m1+1+colskip] * m[m0+1+rowskip][m1];
}

auto hrt::matrix4x4::_det3x3(float m[4][4], int m0, int m1) -> float {

    BOOST_ASSERT_MSG(m0 >= 0 && m0 <= 1, "3x3 submatrix row offset impossible in a 4x4 matrix");
    BOOST_ASSERT_MSG(m1 >= 0 && m1 <= 1, "3x3 submatrix col offset impossible in a 4x4 matrix");

    return m[m0][m1+2] * hrt::matrix4x4::_det2x2(m, m0+1, m1) -
        m[m0][m1+1] * hrt::matrix4x4::_det2x2(m, m0+1, m1, 1) +
        m[m0][m1] * hrt::matrix4x4::_det2x2(m, m0+1, m1+1);
}

auto hrt::matrix4x4::det(float m[4][4]) -> float {

    float d = 1.f;
    float m_tri[4][4];

    hrt::matrix4x4::upper_triangle(m, m_tri);

    for(std::size_t i = 0; i < 4; ++i) {
        d *= m_tri[i][i];
    }

    return d;
}

auto hrt::matrix4x4::upper_triangle(float src[4][4], float dst[4][4]) -> void {

    float ratio;
    std::size_t i, j, k;

    hrt::matrix4x4::copy(src, dst);

    for(i = 0; i < 4; ++i) {
        for(j = 0; j < 4; ++j) {
            if(j > i) {
                ratio = dst[j][i]/dst[i][i];
                for(k = 0; k < 4; ++k) {
                    dst[j][k] -= ratio * dst[i][k];
                }
            }
        }
    }
}

auto hrt::matrix4x4::scale(float src[4][4], float dst[4][4], float s) -> void {

    float *m0 = (float*)(src);
    float *m1 = (float*)(dst);

    for (std::size_t i=0; i<16; ++i) {
        m1[i] = m0[i]*s;
    }
}

auto hrt::matrix4x4::scale(float src[4][4], float s) -> void {

    float *m = (float*)(src);

    for (std::size_t i=0; i<16; ++i) {
        m[i] *= s;
    }
}
