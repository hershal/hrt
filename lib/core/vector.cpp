/*! Vector implementation for Hershal Bhave's hrt renderer */

#include "vector.hpp"
#include "utility/utility_functions.hpp"

auto hrt::core::vector::hasnan() const -> bool {
    if (isnan(x) || isnan(y) || isnan(z)) {
        return true;
    }
    return false;
}

auto hrt::core::vector::normsq() const -> float {
    return this->x*this->x + this->y*this->y + this->z*this->z;
}

auto hrt::core::vector::norm() const -> float {
    return sqrtf(normsq());
}

auto hrt::core::vector::operator=(const hrt::core::vector& v)
    -> hrt::core::vector& {

    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
    return *this;
}

auto hrt::core::vector::operator-() const
    -> hrt::core::vector {

    return (hrt::core::vector(-this->x, -this->y, -this->z));
}

auto hrt::core::vector::operator+(const hrt::core::vector &v) const
    -> hrt::core::vector {

    return (hrt::core::vector(this->x + v.x, this->y + v.y, this->z + v.z));
}

auto hrt::core::vector::operator+=(const hrt::core::vector &v)
    -> hrt::core::vector& {

    this->x += v.x;
    this->y += v.y;
    this->z += v.z;
    return *this;
}

auto hrt::core::vector::operator-(const hrt::core::vector &v) const
    -> hrt::core::vector {

    return (hrt::core::vector(this->x - v.x,
                   this->y - v.y,
                   this->z - v.z));
}

auto hrt::core::vector::operator-=(const hrt::core::vector &v)
    -> hrt::core::vector& {

    this->x -= v.x;
    this->y -= v.y;
    this->z -= v.z;
    return *this;
}

auto hrt::core::vector::operator*(float f) const -> hrt::core::vector {

    return (hrt::core::vector(this->x * f, this->y * f, this->z * f));
}

auto hrt::core::vector::operator*=(float f) -> hrt::core::vector& {

    this->x *= f;
    this->y *= f;
    this->z *= f;
    return *this;
}

auto hrt::core::vector::operator/(float f) const -> hrt::core::vector {

    if(almost_equal_relative(f, 0, pow(10, -6))) {
        printf("SEVERE: hrt::core::vector: Tried to scale-by-reciprocal with a "
               "Zero: f=%f, x=%f, y=%f, z=%f ", f, x, y, z);
    }

    float inverse = 1.0f/f;

    return (hrt::core::vector(this->x * inverse,
                   this->y * inverse,
                   this->z * inverse));
}

auto hrt::core::vector::operator/=(float f) -> hrt::core::vector& {

    if(almost_equal_relative(f, 0, pow(10, -6))) {
        printf("SEVERE: hrt::core::vector: Tried to scale-assign-by-reciprocal with a "
               "Zero: f=%f, x=%f, y=%f, z=%f ", f, x, y, z);
    }

    float inverse = 1.0f/f;

    this->x *= inverse;
    this->y *= inverse;
    this->z *= inverse;
    return *this;
}

auto hrt::core::vector::operator[] (const std::size_t i) const -> float {

    if(i >= NUM_DIMENSIONS) {
        printf("SEVERE: hrt::core::vector: tried to get hrt::core::vector component greater"
               "than the number of dimensions (%i)", NUM_DIMENSIONS);
    }

    /* NOT GUARANTEED PORTABLE! */
    /* TODO: Test this */
    return (&x)[i];
}

auto hrt::core::vector::operator[] (const std::size_t i) -> float& {

    if(i >= NUM_DIMENSIONS) {
        printf("SEVERE: hrt::core::vector: tried to set hrt::core::vector component greater"
               "than the number of dimensions (%i)", NUM_DIMENSIONS);
    }

    /* NOT GUARANTEED PORTABLE! */
    /* TODO: Test this */
    return (&x)[i];
}
