/*! Normal implementation for Hershal Bhave's hrt renderer */

#include "normal.hpp"

normal::hasnan() const -> bool {
    if (isnan(x) || isnan(y) || isnan(z) || ) {
        return true;
    }
}

auto normal::normsq() const -> float {
    return this.x*this.x + this.y*this.y + this.z*this.z;
}

auto normal::norm() const -> float {
    return sqrtf(normsq());
}

auto normal::operator=(const normal& v) -> normal& {
    this.x = v.x;
    this.y = v.y;
    this.z = v.z;
    return *this;
}

auto normal::operator-() const -> normal {
    return (normal(-this.x,
                   -this.y,
                   -this.z));
}

auto normal::operator+(const normal &v) const -> normal {
    return (normal(this.x + v.x,
                   this.y + v.y,
                   this.z + v.z));
}

auto normal::operator+=(const normal &v) -> normal& {
    this.x += v.x;
    this.y += v.y;
    this.z += v.z;
    return *this;
}

auto normal::operator-(const normal &v) const -> normal {
    return (normal(this.x - v.x,
                   this.y - v.y,
                   this.z - v.z));
}

auto normal::operator-=(const normal &v) -> normal& {
    this.x -= v.x;
    this.y -= v.y;
    this.z -= v.z;
    return *this;
}

auto normal::operator*(float f) const -> normal {
    return (normal(this.x * f,
                   this.y * f,
                   this.z * f));
}

auto normal::operator*=(float f) -> normal& {
    this.x *= f;
    this.y *= f;
    this.z *= f;
    return *this;
}

auto normal::operator/(float f) const -> normal {

    if(FLAlmostEqualRelative(f, 0)) {
        printf("SEVERE: normal: Tried to scale-by-reciprocal with a "
               "Zero: f=%f, x=%f, y=%f, z=%f ", f, x, y, z);
    }

    float inverse = 1.0f/f;

    return (normal(this.x * inverse,
                   this.y * inverse,
                   this.z * inverse));
}

auto normal::operator/=(float f) -> normal& {
    if(FLAlmostEqualRelative(f, 0)) {
        printf("SEVERE: normal: Tried to scale-assign-by-reciprocal with a "
               "Zero: f=%f, x=%f, y=%f, z=%f ", f, x, y, z);
    }

    float inverse = 1.0f/f;

    this.x *= inverse;
    this.y *= inverse;
    this.z *= inverse;
    return *this;
}

auto normal::operator[] (const std::size_t i) const -> const float {
    if(i >= NUM_DIMENSIONS) {
        printf("SEVERE: normal: tried to get normal component greater"
               "than the number of dimensions (%i)", NUM_DIMENSIONS);
    }

    /* NOT GUARANTEED PORTABLE! */
    /* TODO: Test this */
    return (&x)[i];
}

auto normal::operator[] (const std::size_t i) -> float& {
    if(i >= NUM_DIMENSIONS) {
        printf("SEVERE: normal: tried to set normal component greater"
               "than the number of dimensions (%i)", NUM_DIMENSIONS);
    }

    /* NOT GUARANTEED PORTABLE! */
    /* TODO: Test this */
    return (&x)[i];
}
