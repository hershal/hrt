#include "utility/matrix4x4.hpp"

auto hrt::matrix4x4::eye(float m[4][4]) -> void {
    memcpy(m, identity_matrix, 16*sizeof(float));
}

/*! \brief Copies a matrix4x4 to another matrix4x4.

  \param src The matrix4x4 to copy from
  \param dst The matrix4x4 to copy to
*/
auto hrt::matrix4x4::copy(float src[4][4], float dst[4][4]) -> void {
    memcpy(dst, src, 16*sizeof(float));
}
