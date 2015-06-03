/*! Matrix4x4 definitions */

#ifndef HRT_UTILITY_MATRIX4X4_HPP
#define HRT_UTILITY_MATRIX4X4_HPP

#include <cmath>
#include <cstdint>
#include <cstring>

namespace hrt {
    namespace matrix4x4 {

        /*! \brief Set a given matrix4x4 to the 4x4 identity matrix.

          \param m The matrix to set to the identity matrix
        */
        auto eye(float m[4][4]) -> void;

        /*! \brief Set a given matrix4x4 to the 4x4 zero matrix.

          \param m The matrix to set to the zero matrix
        */
        auto zero(float m[4][4]) -> void;

        /*! \brief Copies a matrix4x4 to another matrix4x4.

          \param src The matrix4x4 to copy from
          \param dst The matrix4x4 to copy to
        */
        auto copy(float src[4][4], float dst[4][4]) -> void;
    }
}
#endif /* HRT_CORE_MATRIX4X4_HPP */
