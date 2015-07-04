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
    core::ray ro;
    (*world_to_object)(*r, &ro);

    /* Compute the quadractic sphere coefficients */
    float A = ro.direction.x*ro.direction.x +
        ro.direction.y*ro.direction.y + ro.direction.z*ro.direction.z;
    float B = 2 * (ro.direction.x*ro.origin.x +
                   ro.direction.y*ro.origin.y + ro.direction.z*ro.origin.z);
    float C = ro.origin.x*ro.origin.x + ro.origin.y*ro.origin.y +
        ro.origin.z*ro.origin.z - radius*radius;

    /* Solve the quadratic equation for t values */
    float discriminant = B*B - 4*A*C;
    if (discriminant < 0) { return false; }
    float t0 = (-B + std::sqrt(discriminant)) / (2.0f * A);
    float t1 = (-B - std::sqrt(discriminant)) / (2.0f * A);
    if (t0 > t1) {
        float ttmp = t1;
        t1 = t0;
        t0 = ttmp;
    }

    /* Compute intersection distance along ray */
    if (t0 > ro.maxt || t1 < ro.mint) { return false; }
    *t_hit = t0;
    if (t0 < ro.mint) {
        *t_hit = t1;
        if (*t_hit > ro.maxt) { return false; }
    }

    /* Compute sphere hit position and \phi */
    core::point p_hit = ro(*t_hit);
    phi = atan2f(phi_t.y, phi_t.x);
    if (phi < 0.f) phi += 2.f*M_PI;

    /* Test sphere intersection against clipping parameters */
    /* Find a parametric representatino of a sphere hit */
    /* Initialize the DifferentialGeometry from the parametric information */
    /* Update t_hit for quadractic intersection */
    /* compute ray_epsilon for quadratic intersection */

    /* TODO: REMOVE */
    (void) p_hit;
    (void) r;
    (void) t_hit;
    (void) ray_epsilon;
    (void) dg;
    (void) phi;
    (void) phi_t;

    return true;
}

