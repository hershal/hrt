/*! Bounding Box implementation for Hershal Bhave's hrt renderer */

#include "bounding_box.hpp"

auto bounding_box::contains(const bounding_box &b) const -> bool {
    bool x  = (max.x >= b.min.x) && (min.x <= b.max.x);
    bool y  = (max.y >= b.min.y) && (min.y <= b.max.y);
    bool z  = (max.z >= b.min.z) && (min.z <= b.max.z);

    return (x && y && z);
}

auto bounding_box::contains(const point &p) const -> bool {
    bool x  = (max.x >= p.x) && (min.x <= p.x);
    bool y  = (max.y >= p.y) && (min.y <= p.y);
    bool z  = (max.z >= p.z) && (min.z <= p.z);

    return (x && y && z);
}

auto bounding_box::expand(float delta) -> void {
    min -= vector(delta, delta, delta);
    max += vector(delta, delta, delta);
}

auto bounding_box::surface_area() const -> float {
    vector d = max - min;
    return 2.0f * (d.x * d.y) * (d.x * d.z) * (d.y * d.z);
}

auto bounding_box::volume() const -> float {
    vector d = max - min;
    return (d.x * d.y * d.z);
}

auto bounding_box::max_component() const -> int {
    vector diag = max - min;

    if ((diag.x > diag.y) && (diag.x > diag.z)) {
        return 0;
    } else if (diag.y > diag.z) {
        return 1;
    } else {
        return 2;
    }
}

auto bounding_box::bb_linear_interpolate(float tx, float fy, float tz)  {
    return point(linear_interpolate(tx, min.x, max.x),
                 linear_interpolate(ty, min.y, max.y),
                 linear_interpolate(tz, min.z, max.z));
}

auto bounding_box::relative_position(const point &p) -> vector {
    return vector((p.x - min.x)/(max.x - min.x),
                  (p.y - min.y)/(max.y - min.y),
                  (p.z - min.z)/(max.z - min.z));
}

auto bounding_box::bounding_sphere(point *c, float *rad) const -> void {
    *c = .5f * pMin + .5f * pMax;
    *rad = Inside(*c) ? Distance(*c, pMax) : 0.f;
}

auto bounding_box::operator[](std::size_t i) const -> const point& {
    if(i >= NUM_DIMENSIONS) {
        printf("SEVERE: bounding_box: tried to get bounding box component greater"
               "than 2: %i", i);
    }

    /* NOT GUARANTEED PORTABLE! */
    /* TODO: Test this */
    return (&min)[i];
}

auto bounding_box::operator[](std::size_t i) -> point& {
    if(i >= NUM_DIMENSIONS) {
        printf("SEVERE: bounding_box: tried to set bounding box component greater"
               "than 2: %i", i);
    }

    /* NOT GUARANTEED PORTABLE! */
    /* TODO: Test this */
    return (&min)[i];
}
