#include "utility/matrix4x4.hpp"
#include "utility/utility_functions.hpp"
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

auto hrt::matrix4x4::_det2x2(float m[4][4], std::size_t r0, std::size_t r1, std::size_t c0, std::size_t c1) -> float {

    BOOST_ASSERT_MSG((r0 <= 3) && (r1 <= 3),
                     "2x2 submatrix row impossible in a 4x4 matrix");
    BOOST_ASSERT_MSG((c0 <= 3) && (c1 <= 3),
                     "2x2 submatrix col impossible in a 4x4 matrix");

    return m[r0][c0]*m[r1][c1] - m[r0][c1]*m[r1][c0];
}

auto hrt::matrix4x4::_det3x3(float m[4][4],
                             std::size_t r0, std::size_t r1, std::size_t r2,
                             std::size_t c0, std::size_t c1, std::size_t c2)
    -> float {

    BOOST_ASSERT_MSG((r0 <= 3) && (r1 <= 3),
                     "3x3 submatrix row impossible in a 4x4 matrix");
    BOOST_ASSERT_MSG((c0 <= 3) && (c1 <= 3),
                     "3x3 submatrix col impossible in a 4x4 matrix");

    return m[r0][c0] * hrt::matrix4x4::_det2x2(m, r1, r2, c1, c2) -
        m[r0][c1] * hrt::matrix4x4::_det2x2(m, r1, r2, c0, c2) +
        m[r0][c2] * hrt::matrix4x4::_det2x2(m, r1, r2, c0, c1);
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

auto hrt::matrix4x4::inverse(float src[4][4], float dst[4][4]) -> void {

    float m4det = det(src);
    if (std::fabs(m4det) < machine_epsilon) {
        scale(src, 0.f);
    }

    /* STUB */
    (void)dst;
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
