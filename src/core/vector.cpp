/*! Vector implementation for Hershal Bhave's hrt renderer */

#include "vector.hpp"

vector::hasnan() const -> bool {
    if (isnan(x) || isnan(y) || isnan(z) || ) {
        return true;
    }
}

auto vector::normsq() const -> float {
    return this.x*this.x + this.y*this.y + this.z*this.z;
}

auto vector::norm() const -> float {
    return sqrtf(normsq());
}

auto vector::operator-() const -> vector {
    return (vector(-this.x,
                   -this.y,
                   -this.z));
}

auto vector::operator+(const vector &v) const -> vector {
    return (vector(this.x + v.x,
                   this.y + v.y,
                   this.z + v.z));
}

auto vector::operator+=(const vector &v) -> vector& {
    this.x += v.x;
    this.y += v.y;
    this.z += v.z;
    return *this;
}

auto vector::operator-(const vector &v) const -> vector {
    return (vector(this.x - v.x,
                   this.y - v.y,
                   this.z - v.z));
}

auto vector::operator-=(const vector &v) -> vector& {
    this.x -= v.x;
    this.y -= v.y;
    this.z -= v.z;
    return *this;
}

auto vector::operator*(float f) const -> vector {
    return (vector(this.x * f,
                   this.y * f,
                   this.z * f));
}

auto vector::operator*=(float f) -> vector& {
    this.x *= f;
    this.y *= f;
    this.z *= f;
    return *this;
}

auto vector::operator/(float f) const -> vector {

    if(FLAlmostEqualRelative(f, 0)) {
        printf("SEVERE: vector: Tried to scale-by-reciprocal with a "
               "Zero: f=%f, x=%f, y=%f, z=%f ", f, x, y, z);
    }

    float inverse = 1.0f/f;

    return (vector(this.x * inverse,
                   this.y * inverse,
                   this.z * inverse));
}

auto vector::operator/=(float f) -> vector& {
    if(FLAlmostEqualRelative(f, 0)) {
        printf("SEVERE: vector: Tried to scale-assign-by-reciprocal with a "
               "Zero: f=%f, x=%f, y=%f, z=%f ", f, x, y, z);
    }

    float inverse = 1.0f/f;

    this.x *= inverse;
    this.y *= inverse;
    this.z *= inverse;
    return *this;
}

auto vector::operator[] (const std::size_t i) const -> const float {
    if(i >= NUM_DIMENSIONS) {
        printf("SEVERE: vector: tried to get vector component greater"
               "than the number of dimensions (%i)", NUM_DIMENSIONS);
    }

    /* NOT GUARANTEED PORTABLE! */
    /* TODO: Test this */
    return (&x)[i];
}

auto vector::operator[] (const std::size_t i) -> float& {
    if(i >= NUM_DIMENSIONS) {
        printf("SEVERE: vector: tried to set vector component greater"
               "than the number of dimensions (%i)", NUM_DIMENSIONS);
    }

    /* NOT GUARANTEED PORTABLE! */
    /* TODO: Test this */
    return (&x)[i];
}
