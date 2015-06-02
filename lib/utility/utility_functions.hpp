/*! Utility function definitions */

#ifndef HRT_UTILITY_FUNCTIONS_HPP
#define HRT_UTILITY_FUNCTIONS_HPP

#include <cmath>

/*! Constrain the value of a float between a lower and upper bound

  \param n The value to constrain
  \param lower The lower bound to constrain against
  \param upper The upper bound to constrain against
 */
auto clamp(float n, float lower, float upper) -> float {
    return std::fmax(lower, std::fmin(n, upper));
}

/*! Obtain the linearly interpolated value between two floats

  \param t The position (0 to 1) to interpolate between v1 and v2. A
  value of 0 corresponds to exactly v1; a value of 1.0 corresponds to
  exactly v2.
  \param v1 The first value to interpolate between
  \param v2 The second value to interpolate between
 */
auto linear_interpolate(float t, float v1, float v2) -> float {
    return (1.0f - t)*v1 + t*v2;
}

auto inline relative_error(float a, float b) -> float {
    return std::fabs((a - b)/b);
}

auto almost_equal_relative(float a, float b, float epsilon) -> bool {

    /* Remove a division-by-zero possibility */
    if (a == b) {
        return true;
    }

    /* We want to divide by the largest number to minimize roundoff error */
    float relerr;
    if (std::fabs(a) > std::fabs(b)) {
        relerr = relative_error(b, a);
    } else {
        relerr = relative_error(a, b);
    }

    if (relerr <= epsilon) {
        return true;
    }

    return false;
}

#endif /* HRT_UTILITY_FUNCTIONS_HPP */
