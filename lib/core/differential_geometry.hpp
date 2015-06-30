/*! Differential Geometry header for Hershal Bhave's hrt renderer */

#ifndef HRT_CORE_DIFFERENTIAL_GEOMETRY_HPP
#define HRT_CORE_DIFFERENTIAL_GEOMETRY_HPP

#include <cmath>
#include <cstdio>
#include "point.hpp"
#include "normal.hpp"
#include "geometry.hpp"
#include "../shapes/base_shape.hpp"

namespace hrt {
    namespace core {

        namespace shapes {
            class base_shape;
        }

        namespace geometry {
            auto normalize(const core::vector &v) -> core::vector;
        }

        class differential_geometry {
        public:

            /* These variables effectively capture the differential geometry
               surrounding a single point on some surface. */
            core::point p;
            core::normal nn;   /* normalized */
            float u, v;
            shapes::base_shape *shape;
            core::vector dpdu, dpdv;
            core::normal dndu, dndv;

            differential_geometry(const core::point *p,
                                  float u, float v,
                                  const core::vector *dpdu, const core::vector *dpdv,
                                  const core::normal *dndu, const core::normal *dndv,
                                  shapes::base_shape *shape) {

                this->nn = core::normal(geometry::cross(*dpdu, *dpdv));
                *(&(this->p)) = *p;
                this->u = u;
                this->v = v;
                *(&(this->dpdu)) = *dpdu;
                *(&(this->dpdv)) = *dpdv;
                *(&(this->dndu)) = *dndu;
                *(&(this->dndv)) = *dndv;
                this->shape = shape;
            }
        };
    }
}

#endif /* HRT_CORE_DIFFERENTIAL_GEOMETRY_HPP */
