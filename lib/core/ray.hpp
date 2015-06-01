/*! Ray header for Hershal Bhave's hrt renderer */

/*! A Ray is a semi-infinite line which is specified by its origin and
  direction vector. The parametric equation of a ray is as follows
  \f$r(t) = o + t d\f$ where \f$0\le t \le \infty\f$.
*/

#include "point.hpp"
#include "vector.hpp"

#include <cmath>
#include <cfloat>

namespace hrt {
    namespace core {
        class point;
        class vector;

        class ray {
        public:
            ray() : mint(0.0f), maxt(FLT_MAX), depth(0) { }

            ray(const hrt::core::point &origin, const hrt::core::vector &direction,
                float mint = 0.0f, float maxt = FLT_MAX, int depth = 0)
                : origin(origin), direction(direction),
                  mint(mint), maxt(maxt), depth(depth) { }

            /* For basing a ray on a parent ray (sets the new depth index
               based on the parent's) */
            ray(const hrt::core::point &origin, const hrt::core::vector &direction,
                const hrt::core::ray &parent, float mint = 0.0f, float maxt = FLT_MAX)
                : origin(origin), direction(direction),
                  mint(mint), maxt(maxt), depth(parent.depth + 1) { }

            /*! \brief Compute the parametric of the ray equation and return
              the point which indicates the space where the ray stops. */
            hrt::core::point operator()(float t) const { return origin + direction*t; }

            hrt::core::point origin;
            hrt::core::vector direction;

            /* mutable: const methods can modify this data */
            mutable float mint, maxt;

            /* allows the ray to track how many times the light has bounced
               along the current path */
            std::size_t depth;
        };
    }
}
