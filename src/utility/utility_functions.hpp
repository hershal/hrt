/*! Utility function definitions */

/*! Constrain the value of a float between a lower and upper bound

  \param n The value to constrain
  \param lower The lower bound to constrain against
  \param upper The upper bound to constrain against
 */
auto clamp(float n, float lower, float upper) -> float {
    return std::max(lower, std::min(n, upper));
}

/*! Obtain the linearly interpolated value between two floats

  \param t The position (0 to 1) to interpolate between v1 and v2. A
  value of 0 corresponds to exactly v1; a value of 1.0 corresponds to
  exactly v2.
  \param v1 The first value to interpolate between
  \param v2 The second value to interpolate between
 */
auto linear_interpolate(float t, float v1, float v2) {
    return (1.0f - t)*v1 + t*v2
}
