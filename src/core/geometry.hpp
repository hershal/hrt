/*! Geometry header for Hershal Bhave's hrt renderer */

/*! Handedness:

  All the geometry described herein is defined left-handed. That is,
  the X axis points to the right, the Y axis points up, and the Z axis
  points away from the viewer. The "hand" analog can be established as
  such: With one's left hand, the thumb points right, the index finger
  points up, and the middle finger points away from the viewer. The
  corresponding right-handed configuration is the same except due to
  the mirrored nature of the opposite hand, the middle finger happens
  to be forced to point toward the viewer if the other contraints must
  be met, i.e. the thumb must points right and the index finger must
  point up. */

#include "vector.hpp"

/*! \brief The dot product operation.

  The dot product is defined as the relationship between the angle
  between the two vectors: \f$(v \cdot w) = \|v\|\|w\|\cos \theta\f$,
  where \f$\theta\f$ is defined as the angle between \f$v\f$ and
  \f$w\f$. The dot product of two vectors is only zero if the two
  vectors are perpendicular (orthogonal), given that neither of the
  two vectors are degenerate, i.e. the zero vector. If the two vectors
  are unit vectors, then their dot product is simply the cosine of the
  angle between them.
*/
auto dot(const vector& v1, const vector& v2) -> float {
    return v1.x * v2.x
        + v1.y * v2.y
        + v1.z * v2.z;
}

/*! \brief The cross product operation.

  The cross product, in a general sense, returns a vector
  perpendicular to the two input vectors. Since the output vector can
  point in either direction, we have clearly defined that orientation
  beforehand; we will use the "left-handed" orientation. This means
  that when we cross the X unit vector with the Y unit vector, we
  should obtain a unit vector which points in the positive Z
  direction. A similar situation should hold true for all other
  combinations of basis-vector-crossing.
 */
auto cross(const vector &v1, const vector& v2) -> vector {
    return vector((v1.y * v2.z) - (v1.z * v2.y),
                  (v1.z * v2.x) - (v1.x * v2.z),
                  (v1.x * v2.y) - (v1.y * v2.x))
}

/*! \brief Normalizes the given vector. */
auto normalize(const vector &v) -> vector {
    return v/v.norm();
}
