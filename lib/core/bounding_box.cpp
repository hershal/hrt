/*! Bounding Box implementation for Hershal Bhave's hrt renderer */

#include "bounding_box.hpp"
#include "utility/utility_functions.hpp"

auto hrt::core::bounding_box::contains(const hrt::core::bounding_box *b) const
    -> bool {

    bool x  = (max->x >= b->min->x) && (min->x <= b->max->x);
    bool y  = (max->y >= b->min->y) && (min->y <= b->max->y);
    bool z  = (max->z >= b->min->z) && (min->z <= b->max->z);

    return (x && y && z);
}

auto hrt::core::bounding_box::contains(const point *p) const -> bool {

    bool x  = (max->x >= p->x) && (min->x <= p->x);
    bool y  = (max->y >= p->y) && (min->y <= p->y);
    bool z  = (max->z >= p->z) && (min->z <= p->z);

    return (x && y && z);
}

auto hrt::core::bounding_box::expand(float delta) -> void {

    const auto delta_vector = hrt::core::vector(delta, delta, delta);
    *min -= delta_vector;
    *max += delta_vector;
}

auto hrt::core::bounding_box::surface_area() const -> float {

    hrt::core::vector d = *max - *min;
    return 2.0f * (d.x * d.y) * (d.x * d.z) * (d.y * d.z);
}

auto hrt::core::bounding_box::volume() const -> float {

    hrt::core::vector d = *max - *min;
    return (d.x * d.y * d.z);
}

auto hrt::core::bounding_box::max_component() const -> int {

    hrt::core::vector diag = *max - *min;

    if ((diag.x > diag.y) && (diag.x > diag.z)) {
        return 0;
    } else if (diag.y > diag.z) {
        return 1;
    } else {
        return 2;
    }
}

auto hrt::core::bounding_box::bb_linear_interpolate(float tx, float ty, float tz) const
    -> hrt::core::vector* {

    return new hrt::core::vector(linear_interpolate(tx, min->x, max->x),
                                 linear_interpolate(ty, min->y, max->y),
                                 linear_interpolate(tz, min->z, max->z));
}

auto hrt::core::bounding_box::relative_position(const point *p)
    -> hrt::core::vector* {

    return new hrt::core::vector((p->x - min->x)/(max->x - min->x),
                                 (p->y - min->y)/(max->y - min->y),
                                 (p->z - min->z)/(max->z - min->z));
}

auto hrt::core::bounding_box::bounding_sphere(point *c, float *rad) const -> void {

    *c = new hrt::core::point(*min * 0.5f + *max * .5f);
    *rad = Inside(*c) ? Distance(*c, max) : 0.f;
}

auto hrt::core::bounding_box::operator[](std::size_t i) const
    -> const hrt::core::point* {

    if(i >= NUM_DIMENSIONS) {
        printf("SEVERE: bounding_box: tried to get bounding box component >="
               "than 2: %lu", i);
    }

    switch(i) {
    default: return min;
    case 1:  return max;
    }
}

auto hrt::core::bounding_box::operator[](std::size_t i) -> hrt::core::point* {

    if(i >= NUM_DIMENSIONS) {
        printf("SEVERE: bounding_box: tried to set bounding box component >="
               "than 2: %lu", i);
    }

    switch(i) {
    default: return min;
    case 1:  return max;
    }
}
