/*! Utility function definitions */

#ifndef HRT_UTILITY_FUNCTIONS_HPP
#define HRT_UTILITY_FUNCTIONS_HPP

#include <cmath>

/*! Constrain the value of a float between a lower and upper bound

  \param n The value to constrain
  \param lower The lower bound to constrain against
  \param upper The upper bound to constrain against
 */
auto clamp(float n, float lower, float upper) -> float;

/*! Obtain the linearly interpolated value between two floats

  \param t The position (0 to 1) to interpolate between v1 and v2. A
  value of 0 corresponds to exactly v1; a value of 1.0 corresponds to
  exactly v2.
  \param v1 The first value to interpolate between
  \param v2 The second value to interpolate between
 */
auto linear_interpolate(float t, float v1, float v2) -> float;

auto relative_error(float a, float b) -> float;

auto absolute_error(float a, float b) -> float;

auto almost_equal_relative(float a, float b, float epsilon) -> bool;

auto approximately_equal(float actual, float expected) -> bool;

/*! \brief Retuns if a given value is between a low and high limit,
    inclusive. That is, the value may be less or equal to the highest
    value and more than or equal to the lowest value.

    \param val The value to clamp
    \param low The allowed limit low value
    \param high The allowed limit high value
*/
auto is_between_inc(int val, int low, int high) -> bool;

/*! \brief Retuns if a given value is between a low and high limit,
    exclusive. That is, the value must be strictly less that the
    highest value and strictly more than the lowest value.

    \param val The value to clamp
    \param low The unallowed limit low value
    \param high The unallowed limit high value
*/
auto is_between_exc(int val, int low, int high) -> bool;

inline auto to_radians(float deg) -> float { return deg * M_PI / 180; }

static const float machine_epsilon = pow(10, -6);

#endif /* HRT_UTILITY_FUNCTIONS_HPP */
