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

        /*! /brief Computes the determinant of a 2x2 submatrix within
            a 4x4 matrix.

            \param m The 4x4 matrix
            \param m0 Row offset into the 2x2 submatrix within \m
            \param m1 Column offset into the 2x2 submatrix within \m
            \param colskip Number of columns to skip, mostly useful
                when computing determinants for matrices bigger than
                2x2
            \param rowskip Number of rows to skip, mostly useful when
                computing determinants for matrices bigger than 2x2
        */
        auto _det2x2(float m[4][4], int m0, int m1, int colskip=0, int rowskip=0) -> float;

        /*! /brief Computes the determinant of a 3x3 submatrix within
            a 4x4 matrix.

            \param m The 4x4 matrix
            \param m0 Row offset into the 3x3 submatrix within \m
            \param m1 Column offset into the 3x3 submatrix within \m
        */
        auto _det3x3(float m[4][4], int m0, int m1) -> float;

        auto det(float m[4][4]) -> float;

        auto upper_triangle(float src[4][4], float dst[4][4]) -> void;
    }
}
#endif /* HRT_CORE_MATRIX4X4_HPP */
