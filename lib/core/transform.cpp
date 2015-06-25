/*! Point implementation for Hershal Bhave's hrt renderer */

#include "transform.hpp"
#include "geometry.hpp"

friend auto hrt::core::transform::inverse(const hrt::core::transform* t)
    -> hrt::core::transform {
    return hrt::core::transform(t->mat_inv, t->mat);
}

auto hrt::core::transform::rotate(float rads, const vector* axis) {

    vector axis_n = normalize(axis);
    float s = sinf(rads);
    float c = cosf(rads);

    float m[4][4];
    float mt[4][4];

    m[0][0] = a.x * axis.x + (1.f - axis.x * axis.x) * c;
    m[0][1] = axis.x * axis.y * (1.f - c) - axis.z * s;
    m[0][2] = axis.x * axis.z * (1.f - c) + axis.y * s;
    m[0][3] = 0;

    m[1][0] = axis.x * axis.y *  (1.f - c) * axis.z * s;
    m[1][1] = axis.y * axis.y + (1.f - axis.y * axis.y) * c;
    m[1][2] = axis.y * axis.z * (1.f - c) - axis.x * s;
    m[1][3] = 0;

    m[2][0] = axis.x * axis.z * (1.f - c) - axis.y * s;
    m[2][1] = axis.y * axis.z * (1.f - c) + axis.x * s;
    m[2][2] = axis.z * axis.z + (1.f - axis.z * axis.z) * c;
    m[2][3] = 0;

    m[3][0] = 0;
    m[3][1] = 0;
    m[3][2] = 0;
    m[3][3] = 1;

    transpose(m, mt);

    return hrt::core::transform(m, mt);
}
