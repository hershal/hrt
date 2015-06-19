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
          \returns void
        */
        auto identity(float m[4][4]) -> void;

        /*! \brief Set a given matrix4x4 to the 4x4 zero matrix.

          \param m The matrix to set to the zero matrix
          \returns void
        */
        auto zero(float m[4][4]) -> void;

        /*! \brief Copies a matrix4x4 to another matrix4x4.

          \param src The matrix4x4 to copy from
          \param dst The matrix4x4 to copy to
          \returns void
        */
        auto copy(const float src[4][4], float dst[4][4]) -> void;

        /*! /brief Computes the determinant of a 2x2 submatrix within
            a 4x4 matrix.

            \param m The 4x4 matrix
            \param r0 The first row of the 2x2 submatrix
            \param r1 The second row of the 2x2 submatrix
            \param c0 The first col of the 2x2 submatrix
            \param c1 The second col of the 2x2 submatrix
            \returns The value of the determinant
        */
        auto _det2x2(const float m[4][4],
                     std::size_t r0, std::size_t r1,
                     std::size_t c0, std::size_t c1) -> float;

        /*! /brief Computes the determinant of a 3x3 submatrix within
            a 4x4 matrix.

            \param m The 4x4 matrix
            \param r0 The first row of the 3x3 submatrix
            \param r1 The second row of the 3x3 submatrix
            \param r2 The third row of the 3x3 submatrix
            \param c0 The first col of the 3x3 submatrix
            \param c1 The second col of the 3x3 submatrix
            \param c2 The third col of the 3x3 submatrix
            \returns The value of the determinant
        */
        auto _det3x3(const float m[4][4],
                     std::size_t r0, std::size_t r1, std::size_t r2,
                     std::size_t c0, std::size_t c1, std::size_t c2) -> float;

        /*! /brief Computes the determinant of a 4x4 matrix
          \param m The 4x4 matrix
          \returns The value of the determinant
        */
        auto det(const float m[4][4]) -> float;

        auto upper_triangle(const float src[4][4], float dst[4][4]) -> void;

        /*! /brief Computes the inverse of a matrix.

          \param src The source matrix to compute the determinant of
          \param dst The matrix to store the computed determinant into
          \returns void
        */
        auto inverse(const float src[4][4], float dst[4][4]) -> void;

        auto scale(const float src[4][4], float dst[4][4], float s) -> void;

        auto scale(float src[4][4], float s) -> void;
    }
}
#endif /* HRT_CORE_MATRIX4X4_HPP */
