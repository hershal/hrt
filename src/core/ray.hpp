/*! Ray header for Hershal Bhave's hrt renderer */

/*! A Ray is a semi-infinite line which is specified by its origin and
    direction vector. The parametric equation of a ray is as follows
    \f$r(t) = o + t d\f$ where \f$0\le t \le \infty\f$.
*/

#include "point.hpp"
#include "vector.hpp"

#include <cmath>
#include <cfloat>

class ray {
public:
    ray() : mint(0.0f), maxt(FLT_MAX), depth(0) { }

    ray(const point &origin, const vector &direction,
        float mint = 0.0f, float maxt = FLT_MAX, int depth = 0)
        : origin(origin), direction(direction),
          mint(mint), maxt(maxt), depth(depth) { }

    /* For basing a ray on a parent ray (sets the new depth index
       based on the parent's) */
    ray(const point &origin, const vector &direction, const ray &parent,
        float mint = 0.0f, float maxt = FLT_MAX)
        : origin(origin), direction(direction),
          mint(mint), maxt(maxt), depth(parent.depth + 1) { }

    /*! \brief Compute the parametric of the ray equation and return
        the point which indicates the space where the ray stops. */
    point operator()(float t) const { return o + d*t }

    point origin;
    vector direction;

    /* mutable: const methods can modify this data */
    mutable float mint, maxt;

    /* allows the ray to track how many times the light has bounced
       along the current path */
    int depth;
}
