/*! Sphere implementation for Hershal Bhave's hrt renderer */

#include "sphere.hpp"

auto hrt::shapes::sphere::object_bound() const -> hrt::core::bounding_box {

    hrt::core::point p1, p2;
    p1 = hrt::core::point(-radius, -radius, z_min);
    p2 = hrt::core::point( radius,  radius, z_max);

    return hrt::core::bounding_box(&p1, &p2);
}

auto hrt::shapes::sphere::can_intersect() const -> bool { return true; }

auto hrt::shapes::sphere::intersect(const hrt::core::ray *r, float *t_hit,
                                    float *ray_epsilon,
                                    hrt::core::differential_geometry *dg) const -> bool {
    float phi;
    hrt::core::point phi_t;

    /* Transform the ray to object space */
    /* Compute the quadractic sphere coefficients */
    /* Solve the quadratic equation for t values */
    /* Test sphere intersection against clipping parameters */
    /* Find a parametric representatino of a sphere hit */
    /* Initialize the DifferentialGeometry from the parametric information */
    /* Update t_hit for quadractic intersection */
    /* compute ray_epsilon for quadratic intersection */

    /* TODO: REMOVE */
    (void) r;
    (void) t_hit;
    (void) ray_epsilon;
    (void) dg;
    (void) phi;
    (void) phi_t;

    return true;
}

