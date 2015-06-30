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
            differential_geometry(const core::point *p, const core::normal *n,
                                  float u, float v, core::vector *dpdu,
                                  core::vector *dpdv, core::normal *dndu,
                                  core::normal *dndv, shapes::base_shape *shape) {

                this->nn = core::normal(geometry::normalize(*n));

                *(&(this->p)) = *p;
                this->u = u;
                this->v = v;
                *(&(this->dpdu)) = *dpdu;
                *(&(this->dpdv)) = *dpdv;
                *(&(this->dndu)) = *dndu;
                *(&(this->dndv)) = *dndv;
                this->shape = shape;
            }

        private:
            core::point p;
            core::normal nn;   /* normalized */
            float u, v;
            shapes::base_shape *shape;
            core::vector dpdu, dpdv;
            core::normal dndu, dndv;
        };
    }
}

#endif /* HRT_CORE_DIFFERENTIAL_GEOMETRY_HPP */
