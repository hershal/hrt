/*! Bounding Box header for Hershal Bhave's hrt renderer */

/*! A Bounding Box is a three-dimensional bounds volume which encloses
  an object. This optimizes the ray tracing substantially, since we
  can enclose an area around a bounding box and only compute rays
  which intersect within this box to avoid further computation of
  rays which don't actually end up influencing the pixel colors. We
  chose to use a square bounding box which is specified by two
  points. This scheme is called the Axis-Aligned-Bounding-Box
  (AABB). */

#ifndef HRT_CORE_BOUNDING_BOX_HPP
#define HRT_CORE_BOUNDING_BOX_HPP

#include "point.hpp"
#include "vector.hpp"

#include <cmath>
#include <cfloat>
#include <cstdio>

namespace hrt {
    namespace core {
        class vector;
        class point;

        class bounding_box {
        public:
            bounding_box() {
                min = new hrt::core::point(-FLT_MAX, -FLT_MAX, -FLT_MAX);
                max = new hrt::core::point(FLT_MAX, FLT_MAX, FLT_MAX);
            }

            /*! \brief Constructor to enclose a single point around a
              bounding box. */
            bounding_box(const hrt::core::point *p) {
                min = new hrt::core::point(p->x, p->y, p->z);
                max = new hrt::core::point(p->x, p->y, p->z);
            }

            /*! \brief Constructor which creates a bounding box about two points. */
            bounding_box(const hrt::core::point *p1, const hrt::core::point *p2) {
                min = new hrt::core::point(std::fmin(p1->x, p2->x),
                    std::fmin(p1->y, p2->y), std::fmin(p1->z, p2->z));
                max = new hrt::core::point(std::fmax(p1->x, p2->x),
                    std::fmax(p1->y, p2->y), std::fmax(p1->z, p2->z));
            }

            /*! \brief Returns whether or not a given bounding box is
              completely contained within this bounding box. */
            auto contains(const bounding_box *b) const -> bool;

            /*! \breif Returns whether or not a given point is within this
              bounding box. */
            auto contains(const point *p) const -> bool;

            /*! \brief Expand the bounding box by a constant factor. */
            auto expand(float delta) -> void;

            /*! \brief Compute the surface area of the bounding box. */
            auto surface_area() const -> float;

            /*! \brief Compute the volume enclosed by the bounding box. */
            auto volume() const -> float;

            /*! \brief Returns which axis is the longest */
            auto max_component() const -> int;

            /*! \brief Obtain the linearly interpolated point between the two
              bounding box corners. */
            auto bb_linear_interpolate(float tx, float fy, float tz) const
                -> hrt::core::vector*;

            /*! \brief Obtain the position of a point relative to the bounding
              box's min and max points. A return value of point (0,0,0)
              corresponds to the min bound and a return value of point
              (1,1,1) corresponds to the max bound. */
            auto relative_position(const point *p)
                -> hrt::core::vector*;

            /*! \brief Obtaint the bounding sphere corresponding to this
              bounding box. */
            auto bounding_sphere(point *c, float *rad) const -> void;

            /*! \brief bounding box get-value operator */
            auto operator[](std::size_t i) const -> const hrt::core::point*;

            /*! \brief bounding box set-value operator */
            auto operator[](std::size_t i) -> hrt::core::point*;

            hrt::core::point *min;
            hrt::core::point *max;
        };
    }
}

#endif /* HRT_CORE_BOUNDING_BOX_HPP */
