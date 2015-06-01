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

#ifndef HRT_CORE_GEOMETRY_HPP
#define HRT_CORE_GEOMETRY_HPP

#include "vector.hpp"
#include "point.hpp"
#include "ray.hpp"
#include "bounding_box.hpp"

/*! \brief Compute the dot product between two vectors.

  The dot product is defined as the relationship between the angle
  between the two vectors: \f$(v \cdot w) = \|v\|\|w\|\cos \theta\f$,
  where \f$\theta\f$ is defined as the angle between \f$v\f$ and
  \f$w\f$. The dot product of two vectors is only zero if the two
  vectors are perpendicular (orthogonal), given that neither of the
  two vectors are degenerate, i.e. the zero vector. If the two vectors
  are unit vectors, then their dot product is simply the cosine of the
  angle between them. Hence, if the two vectors lie in the same
  hemisphere as one another, the cosine of angle between them is
  positive; negative if the vectors are pointing in opposite
  hemispheres.
*/
auto dot(const vector& v1, const vector& v2) -> float {
    return v1.x * v2.x
        + v1.y * v2.y
        + v1.z * v2.z;
}

/*! \brief Compute the dot product between two normals.

  The computation is the same as the vector-vector dot product.
*/
auto dot(const normal& n1, const normal& n2) -> float {
    return n1.x * n2.x
        + n1.y * n2.y
        + n1.z * n2.z;
}

/*! \brief Compute the dot product between a normal and a vector.

  The computation is the same as the vector-vector dot product.
*/
auto dot(const normal& n1, const vector& v2) -> float {
    return n1.x * v2.x
        + n1.y * v2.y
        + n1.z * v2.z;
}

/*! \brief Compute the dot product between a vector and a normal.

  The computation is the same as the vector-vector dot product.
*/
auto dot(const vector& v1, const normal& n2) -> float {
    return v1.x * n2.x
        + v1.y * n2.y
        + v1.z * n2.z;
}

/*! \brief Compute the cross product between two vectors.

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

/*! \brief Normalizes the given normal. */
auto normalize(const normal &n) -> normal {
    return n/n.norm();
}

/*! \brief Generates a new coordinate system given a single vector.
  \param v1 The given vector to create the new coordinate system
  based on
  \param v2 The first associated output vector
  \param v3 The second associated output vector

  Reference [This Matlab comment](http://www.mathworks.com/matlabcentral/answers/72631-create-orthonormal-basis-from-a-given-vector)
  for how this was determined.
*/
auto gen_coord_system(const vector &v1, vector* v2, vector* v3) -> void {

    /* TODO: Test if there are any differences in accuracy and speed
       dependent on which one was picked. Theoretically they should
       give the same answer, but it's possible that numerically one
       could be more stable than the other if one is very small (henc
       the greater-than check). I'm sure in pathological cases there
       may be some differences. */

   if (fabsf(v1.x) > fabsf(v1.y)) {
        float inv_norm = 1.f / sqrtf(v1.x*v1.x + v1.z*v1.z);
        *v2 = vector(-v1.z * inv_norm, 0.f, v1.x * inv_norm);
    } else {
        float inv_norm = 1.f / sqrtf(v1.y*v1.y + v1.z*v1.z);
        *v2 = vector(0.f, v1.z * inv_norm, -v1.y * inv_norm);
    }

    *v3 = cross(v1, *v2);
}

/*! \brief Compute the distance between two points, squared */
auto distsq(const point &p1, const point &p2) {
    return (p1 - p2).norm();
}

/*! \brief Compute the distance between two points */
auto dist(const point &p1, const point &p2) {
    return (p1 - p2).normsq();
}

/*! \brief Flip the normal so that it faces the same hemisphere as the
    vector.

  \param n1 The normal to flip
  \param v2 The vector the point the normal toward
*/
auto face_toward(const normal &n1, const vector &v2) -> normal {
    return (dot(n1, v2) < 0.0f) ? -n1 : n1;
}

/* \brief Flip the first normal so that it faces the same hemisphere
    as the second normal.

    This computation is the same as the normal-vector method.
*/
auto face_toward(const normal &n1, const normal &n2) -> normal {
    return (dot(n1, n2) < 0.0f) ? -n1 : n1;
}

/* \brief Flip the vector so that it faces the same hemisphere
    as the normal.

    This computation is the same as the normal-vector method.
*/
auto face_toward(const vector &v1, const normal &n2) -> normal {
    return (dot(v1, n2) < 0.0f) ? -v1 : v1;
}

/* \brief Flip the first vector so that it faces the same hemisphere
    as the second vector.

    This computation is the same as the normal-vector method.
*/
auto face_toward(const vector &v1, const vector &v2) -> normal
    return (dot(v1, v2) < 0.0f) ? -v1 : v1;
}

/*! \brief Construct a new bounding box from an existing one which
  encloses an additional point. */
auto bb_union
    (const bounding_box &b, const point &p) -> bounding_box {

    bounding_box returning_box = b;

    returning_box.min.x = min(b.min.x, p.x);
    returning_box.min.y = min(b.min.y, p.y);
    returning_box.min.z = min(b.min.z, p.z);

    returning_box.max.x = max(b.max.x, p.x);
    returning_box.max.y = max(b.max.y, p.y);
    returning_box.max.z = max(b.max.z, p.z);

    return returning_box;
}

/*! \brief Construct a new bounding box which encloses two existing
  bounding boxes. */
auto friend bb_union
    (const bounding_box &b1, const bounding_box &b2) -> bounding_box {

    bounding_box returning_box = b;

    returning_box.min.x = min(b1.min.x, b2.min.x);
    returning_box.min.y = min(b1.min.y, b2.min.y);
    returning_box.min.z = min(b1.min.z, b2.min.z);

    returning_box.max.x = max(b1.max.x, b2.max.x);
    returning_box.max.y = max(b1.max.y, b2.max.y);
    returning_box.max.z = max(b1.max.z, b2.max.z);

    return returning_box;
}

#endif /* HRT_CORE_GEOMETRY_HPP */
