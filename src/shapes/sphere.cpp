/*! Sphere implementation for Hershal Bhave's hrt renderer */

#include "sphere.hpp"

auto sphere::object_bound() const -> bounding_box {
    return bounding_box(point(-radius, -radius, z_min),
                        point( radius,  radius, z_max));
}
auto sphere::can_intersect() const -> bool { return true; }

auto sphere::XB
intersect(const ray &r, float* t_hit,
               float* ray_epsilon,
               differential_geometry *dg) const -> bool {

    float phi;
    point phi_t;

    /* Transform the ray to object space */
    /* Compute the quadractic sphere coefficients */
    /* Solve the quadratic equation for t values */
    /* Test sphere intersection against clipping parameters */
    /* Find a parametric representatino of a sphere hit */
    /* Initialize the DifferentialGeometry from the parametric information */
    /* Update t_hit for quadractic intersection */
    /* compute ray_epsilon for quadratic intersection */

    return true;
}

