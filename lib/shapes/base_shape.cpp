/*! Shape implementation for Hershal Bhave's hrt renderer */

#include "base_shape.hpp"

#include <cstdio>

auto base_shape::world_bound() const -> bounding_box {
    return (*object_to_world)(object_bound());
}

/* The default shape can always calculate its own intersections */
auto base_shape::can_intersect() const -> bool {
    return true;
}

auto base_shape::refine(std::vector<std::shared_ptr<base_shape> > &refined) const
    -> void {
    printf("ERROR: SEVERE: Cannot refine an atomic shape\n");
}

auto base_shape::intersect(const ray &r,
                      float* t_hit,
                      float* ray_epsilon,
                      differential_geometry *dg) const -> bool {
    printf("ERROR: SEVERE: Cannot call intersect on a general shape\n");
    return false;
}

auto base_shape::intersect_predicate(const ray &r) const -> bool {
    printf("ERROR: SEVERE: Cannot call intersect_predicate on a general shape\n");
    return false;
}

auto base_shape::surface_area const -> const float {
    printf("ERROR: SEVERE: Cannot call surface_area on a general shape\n");
    return 0.0f;
}
