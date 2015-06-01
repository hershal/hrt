/*! Sphere header for Hershal Bhave's hrt renderer */
/*! The sphere class represents a sphere centered at the origin in
  object space */

/* Spheres are a special case of quadrics, where the familiar equation
   x^2 + y^2 + z^2 - r^2 = 0 holds. */

#include "base_shape.hpp"

#include "core/bounding_box.hpp"
#include "utility/utility_functions.hpp"

namespace hrt {
    namespace shapes {

        class sphere : public base_shape {
        public:
            sphere(transform* o_w, transform* w_o, bool reverse,
                   float radius, float z_min, float z_max, float phi_max)
                : shape(o_w, w_o, reverse) {
                this->radius = radius;
                this->phi_max = phi_max;
                this->z_min = z_min;
                this->z_max = z_max;
                this->theta_min = acosf(clamp(z_min/radius, -1.0f, 1.0f));
                this->theta_max = acosf(clamp(z_max/radius, -1.0f, 1.0f));
            }

            auto object_bound() const -> hrt::core::bounding_box;
            auto can_intersect() const -> bool;
            auto intersect_predicate(const hrt::core::ray &r) const -> bool;
            auto intersect(const hrt::core::ray &r, float* t_hit,
                           float* ray_epsilon,
                           differential_geometry *dg) const -> bool;
            auto refine(std::vector<base_shape*> &refined) const -> void;
            auto surface_area() const -> float;

        private:

            float radius;
            float phi_max;
            float z_min;
            float z_max;
            float theta_min;
            float theta_max;
        };
    }
}
