/*! Point implementation for Hershal Bhave's hrt renderer */

#include "transform.hpp"
#include "geometry.hpp"

auto hrt::core::transform::inverse(const hrt::core::transform* t)
    -> hrt::core::transform {
    return hrt::core::transform(t->mat_inv, t->mat);
}

auto hrt::core::transform::rotate(float rads, const hrt::core::vector* axis)
    -> hrt::core::transform {

    hrt::core::vector axis_n = geometry::normalize(*axis);
    float s = sinf(rads);
    float c = cosf(rads);

    float m[4][4];
    float mt[4][4];

    m[0][0] = axis_n.x * axis_n.x + (1.f - axis_n.x * axis_n.x) * c;
    m[0][1] = axis_n.x * axis_n.y * (1.f - c) - axis_n.z * s;
    m[0][2] = axis_n.x * axis_n.z * (1.f - c) + axis_n.y * s;
    m[0][3] = 0;

    m[1][0] = axis_n.x * axis_n.y *  (1.f - c) * axis_n.z * s;
    m[1][1] = axis_n.y * axis_n.y + (1.f - axis_n.y * axis_n.y) * c;
    m[1][2] = axis_n.y * axis_n.z * (1.f - c) - axis_n.x * s;
    m[1][3] = 0;

    m[2][0] = axis_n.x * axis_n.z * (1.f - c) - axis_n.y * s;
    m[2][1] = axis_n.y * axis_n.z * (1.f - c) + axis_n.x * s;
    m[2][2] = axis_n.z * axis_n.z + (1.f - axis_n.z * axis_n.z) * c;
    m[2][3] = 0;

    m[3][0] = 0;
    m[3][1] = 0;
    m[3][2] = 0;
    m[3][3] = 1;

    matrix4x4::transpose(m, mt);

    return hrt::core::transform(m, mt);
}
