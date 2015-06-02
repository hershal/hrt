/*! Utility function definitions */

#ifndef HRT_UTILITY_FUNCTIONS_HPP
#define HRT_UTILITY_FUNCTIONS_HPP

#include <cmath>
#include <boost/assert.hpp>

/*! Constrain the value of a float between a lower and upper bound

  \param n The value to constrain
  \param lower The lower bound to constrain against
  \param upper The upper bound to constrain against
 */
auto clamp(float n, float lower, float upper) -> float {

    BOOST_ASSERT_MSG(lower < upper, "clamp low value >= upper value");
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

/*! \brief Retuns if a given value is between a low and high limit,
    inclusive. That is, the value may be less or equal to the highest
    value and more than or equal to the lowest value.

    \param val The value to clamp
    \param low The allowed limit low value
    \param high The allowed limit high value
*/
auto is_between_inc(int val, int low, int high) -> bool {
    return ((val >= low) && (val <= high));
}

/*! \brief Retuns if a given value is between a low and high limit,
    exclusive. That is, the value must be strictly less that the
    highest value and strictly more than the lowest value.

    \param val The value to clamp
    \param low The unallowed limit low value
    \param high The unallowed limit high value
*/
auto is_between_exc(int val, int low, int high) -> bool {
    return ((val > low) && (val < high));
}

static const float machine_epsilon = pow(10, -6);

#endif /* HRT_UTILITY_FUNCTIONS_HPP */
