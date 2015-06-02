/*! Matrix4x4 definitions */

#ifndef HRT_UTILITY_MATRIX4X4_HPP
#define HRT_UTILITY_MATRIX4X4_HPP

#include <cmath>
#include <cstdint>

/*! Constrain the value of a float between a lower and upper bound

  \param n The value to constrain
  \param lower The lower bound to constrain against
  \param upper The upper bound to constrain against
 */
auto eye(float m[4][4]) -> float {

    uint8_t i0, i1;

    for (uint8_t i=0; i<16; ++i) {
        i0 = (i & 0xff00) >> 2;
        i1 = i & 0x00ff;
        m[i0][i1] = i0 == i1;
    }
}

#endif /* HRT_CORE_MATRIX4X4_HPP */
