/*! Matrix4x4 definitions */

#ifndef HRT_UTILITY_MATRIX4X4_HPP
#define HRT_UTILITY_MATRIX4X4_HPP

#include <cmath>
#include <cstdint>
#include <cstring>

namespace hrt {
    namespace matrix4x4 {

        static float identity_matrix[4][4] = {{1.f, 0.f, 0.f, 0.f},
                                              {0.f, 1.f, 0.f, 0.f},
                                              {0.f, 0.f, 1.f, 0.f},
                                              {0.f, 0.f, 0.f, 1.f}};

        /*! Constrain the value of a float between a lower and upper bound

          \param n The value to constrain
          \param lower The lower bound to constrain against
          \param upper The upper bound to constrain against
        */
        auto eye(float m[4][4]) -> void {
            memcpy(m, identity_matrix, 16*sizeof(float));
        }

        auto copy(float src[4][4], float dst[4][4]) -> void {
            memcpy(dst, src, 16*sizeof(float));
        }
    }
}
#endif /* HRT_CORE_MATRIX4X4_HPP */
