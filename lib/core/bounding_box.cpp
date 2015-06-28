/*! Bounding Box implementation for Hershal Bhave's hrt renderer */

#include "bounding_box.hpp"
#include "utility/utility_functions.hpp"

auto hrt::core::bounding_box::contains(const hrt::core::bounding_box *b) const
    -> bool {

    bool x  = (max.x >= b->min.x) && (min.x <= b->max.x);
    bool y  = (max.y >= b->min.y) && (min.y <= b->max.y);
    bool z  = (max.z >= b->min.z) && (min.z <= b->max.z);

    return (x && y && z);
}

auto hrt::core::bounding_box::contains(const point *p) const -> bool {

    bool x  = (max.x >= p->x) && (min.x <= p->x);
    bool y  = (max.y >= p->y) && (min.y <= p->y);
    bool z  = (max.z >= p->z) && (min.z <= p->z);

    return (x && y && z);
}

auto hrt::core::bounding_box::expand(float delta) -> void {

    const auto delta_vector = hrt::core::vector(delta, delta, delta);
    min -= delta_vector;
    max += delta_vector;
}

auto hrt::core::bounding_box::surface_area() const -> float {

    hrt::core::vector d = max - min;
    return 2.0f * (d.x * d.y) * (d.x * d.z) * (d.y * d.z);
}

auto hrt::core::bounding_box::volume() const -> float {

    hrt::core::vector d = max - min;
    return (d.x * d.y * d.z);
}

auto hrt::core::bounding_box::max_component() const -> int {

    hrt::core::vector diag = max - min;

    if ((diag.x > diag.y) && (diag.x > diag.z)) {
        return 0;
    } else if (diag.y > diag.z) {
        return 1;
    } else {
        return 2;
    }
}

auto hrt::core::bounding_box::bb_linear_interpolate(float tx, float ty, float tz) const
    -> hrt::core::vector {

    return hrt::core::vector(linear_interpolate(tx, min.x, max.x),
                             linear_interpolate(ty, min.y, max.y),
                             linear_interpolate(tz, min.z, max.z));
}

auto hrt::core::bounding_box::relative_position(const point *p)
    -> hrt::core::vector {

    return hrt::core::vector((p->x - min.x)/(max.x - min.x),
                             (p->y - min.y)/(max.y - min.y),
                             (p->z - min.z)/(max.z - min.z));
}

auto hrt::core::bounding_box::bounding_sphere(point *c, float *rad) const -> void {

    *c = new hrt::core::point(this->min * 0.5f + this->max * .5f);
    *rad = contains(c) ? distance(c, &max) : 0.f;
}

auto hrt::core::bounding_box::operator[](std::size_t i) const
    -> const hrt::core::point* {

    if(i >= NUM_DIMENSIONS) {
        printf("SEVERE: bounding_box: tried to get bounding box component >="
               "than 2: %lu", i);
    }

    switch(i) {
    default: return &min;
    case 1:  return &max;
    }
}

auto hrt::core::bounding_box::operator[](std::size_t i) -> hrt::core::point* {

    if(i >= NUM_DIMENSIONS) {
        printf("SEVERE: bounding_box: tried to set bounding box component >="
               "than 2: %lu", i);
    }

    switch(i) {
    default: return &min;
    case 1:  return &max;
    }
}

/* TODO: Why would accepting a bounding box as input be necessary? */
auto bb_union(const hrt::core::bounding_box *b,
              const hrt::core::point *p)
    -> hrt::core::bounding_box {

    /* TODO: check that this does not destroy b's data */
    hrt::core::bounding_box ret = *b;

    ret.min.x = std::fmin(b->min.x, p->x);
    ret.min.y = std::fmin(b->min.y, p->y);
    ret.min.z = std::fmin(b->min.z, p->z);
    ret.max.x = std::fmax(b->max.x, p->x);
    ret.max.y = std::fmax(b->max.y, p->y);
    ret.max.z = std::fmax(b->max.z, p->z);
    return ret;
}

auto hrt::core::bounding_box::bb_union(const hrt::core::point *p) -> void {

    min.x = std::fmin(min.x, p->x);
    min.y = std::fmin(min.y, p->y);
    min.z = std::fmin(min.z, p->z);
    max.x = std::fmax(max.x, p->x);
    max.y = std::fmax(max.y, p->y);
    max.z = std::fmax(max.z, p->z);
}

auto bb_union
(const hrt::core::bounding_box &b1, const hrt::core::bounding_box &b2)
    -> hrt::core::bounding_box {

    hrt::core::bounding_box returning_box;

    returning_box.min.x = fmin(b1.min.x, b2.min.x);
    returning_box.min.y = fmin(b1.min.y, b2.min.y);
    returning_box.min.z = fmin(b1.min.z, b2.min.z);

    returning_box.max.x = fmax(b1.max.x, b2.max.x);
    returning_box.max.y = fmax(b1.max.y, b2.max.y);
    returning_box.max.z = fmax(b1.max.z, b2.max.z);

    return returning_box;
}
