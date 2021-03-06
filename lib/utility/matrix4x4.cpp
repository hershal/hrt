#include "utility/matrix4x4.hpp"
#include "utility/utility_functions.hpp"
#include <boost/assert.hpp>

static float identity_matrix[4][4] =
    {{1.f, 0.f, 0.f, 0.f},
     {0.f, 1.f, 0.f, 0.f},
     {0.f, 0.f, 1.f, 0.f},
     {0.f, 0.f, 0.f, 1.f}};

auto hrt::matrix4x4::identity(float m[4][4]) -> void {
    memcpy(m, identity_matrix, 16*sizeof(float));
}

auto hrt::matrix4x4::identityp(float m[4][4]) -> bool {
    return hrt::matrix4x4::equalp(m, identity_matrix);
}

auto hrt::matrix4x4::zero(float m[4][4]) -> void {
    float *f = (float*)(m);
    for (uint8_t i=0; i<16; ++i) {
        f[i] = 0.f;
    }
}

auto hrt::matrix4x4::copy(const float src[4][4], float dst[4][4]) -> void {
    memcpy(dst, src, 16*sizeof(float));
}

auto hrt::matrix4x4::_det2x2(const float m[4][4],
                             std::size_t r0, std::size_t r1,
                             std::size_t c0, std::size_t c1) -> float {

    BOOST_ASSERT_MSG((r0 <= 3) && (r1 <= 3),
                     "2x2 submatrix row impossible in a 4x4 matrix");
    BOOST_ASSERT_MSG((c0 <= 3) && (c1 <= 3),
                     "2x2 submatrix col impossible in a 4x4 matrix");

    return m[r0][c0]*m[r1][c1] - m[r0][c1]*m[r1][c0];
}

auto hrt::matrix4x4::_det3x3(const float m[4][4],
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

auto hrt::matrix4x4::det(const float m[4][4]) -> float {

    float d = 1.f;
    float m_tri[4][4];

    hrt::matrix4x4::upper_triangle(m, m_tri);

    for(std::size_t i = 0; i < 4; ++i) {
        d *= m_tri[i][i];
    }

    return d;
}

auto hrt::matrix4x4::upper_triangle(const float src[4][4],
                                    float dst[4][4]) -> void {

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

auto hrt::matrix4x4::inverse(const float src[4][4],
                             float dst[4][4]) -> void {

    float m4det = det(src);

    /* zero-cancel the dst matrix if src's determinant is zero (the
       src matrix is singular).*/
    if (std::fabs(m4det) < machine_epsilon) {
        scale(src, dst, 0.f);
    }

    /* Use the adjugate formula to calculate the inverse of the
       matrix. */
    size_t r[3], c[3], counter, rr, cc;
    for (std::size_t i=0; i<4; ++i) {
        for(std::size_t j=0; j<4; ++j) {

            rr = 0;
            cc = 0;
            for (counter=0; counter<3; ++counter) {
                /* Optimization: Note that i and j are swapped
                   here. This is done to remove the transpose
                   operation normally required for the adjugate
                   forumla. */
                r[counter] = rr == j ? ++rr : rr;
                c[counter] = cc == i ? ++cc : cc;
                ++cc; ++rr;
            }

            dst[i][j] = (((i+j)%2==1)*(-2.f) + 1) *
                _det3x3(src, r[0], r[1], r[2], c[0], c[1], c[2]);
        }
    }

    scale(dst, 1/m4det);
}

auto hrt::matrix4x4::scale(const float src[4][4],
                           float dst[4][4], float s) -> void {

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

auto hrt::matrix4x4::equalp(float m0[4][4], float m1[4][4]) -> bool {

    for (int i=0; i<4; ++i) {
        for (int j=0; j<4; ++j) {
            if (!::approximately_equal(m0[i][j], m1[i][j])) {
                return false;
            }
        }
    }
    return true;
}

auto hrt::matrix4x4::transpose(float src[4][4], float dst[4][4]) -> void {

    for (int i=0; i<4; ++i) {
        for (int j=0; j<4; ++j) {
            dst[i][j] = src[j][i];
        }
    }
}
auto hrt::matrix4x4::transpose(float m[4][4]) -> void {

    float tmp;
    for (int i=0; i<3; ++i) {
        for (int j=i+1; j<4; ++j) {
            tmp = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = tmp;
        }
    }
}

auto hrt::matrix4x4::mul(const float m0[4][4], const float m1[4][4], float dst[4][4]) -> void {

    for (int i=0; i<4; ++i) {
        for (int j=0; j<4; ++j) {
            dst[i][j] = m0[i][0] * m1[0][j] +
                m0[i][1] * m1[1][j] +
                m0[i][2] * m1[2][j] +
                m0[i][3] * m1[3][j];
        }
    }
}
