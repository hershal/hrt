/*! Shape implementation for Hershal Bhave's hrt renderer */

#include "base_shape.hpp"
#include "../core/differential_geometry.hpp"

#include <cstdio>

auto hrt::shapes::base_shape::world_bound() const -> hrt::core::bounding_box {
    return object_bound();
}

/* The default shape can always calculate its own intersections */
auto hrt::shapes::base_shape::can_intersect() const -> bool {
    return true;
}

auto hrt::shapes::base_shape::refine(std::vector<hrt::shapes::base_shape*> &refined) const
    -> void {
    (void) refined;
    printf("ERROR: SEVERE: Cannot refine an atomic shape\n");
}

auto hrt::shapes::base_shape::intersect(const hrt::core::ray &r,
                           float* t_hit, float* ray_epsilon,
                           hrt::core::differential_geometry *dg) const -> bool {
    (void) r;
    (void) t_hit;
    (void) ray_epsilon;
    (void) dg;
    printf("ERROR: SEVERE: Cannot call intersect on a general shape\n");
    return false;
}

auto hrt::shapes::base_shape::intersectp(const hrt::core::ray &r) const -> bool {
    (void) r;
    printf("ERROR: SEVERE: Cannot call intersectp on a general shape\n");
    return false;
}

auto hrt::shapes::base_shape::surface_area() const -> float {
    printf("ERROR: SEVERE: Cannot call surface_area on a general shape\n");
    return 0.0f;
}
