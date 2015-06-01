/*! Normal implementation for Hershal Bhave's hrt renderer */

#include "normal.hpp"
#include "utility_functions.hpp"

auto hrt::core::normal::hasnan() const -> bool {

    if (isnan(x) || isnan(y) || isnan(z)) {
        return true;
    }
    return false;
}

auto hrt::core::normal::normsq() const -> float {

    return this->x*this->x + this->y*this->y + this->z*this->z;
}

auto hrt::core::normal::norm() const -> float {

    return sqrtf(normsq());
}

auto hrt::core::normal::operator=(const hrt::core::normal& v)
    -> hrt::core::normal& {

    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
    return *this;
}

auto hrt::core::normal::operator-() const -> hrt::core::normal {

    return (hrt::core::normal(-this->x, -this->y, -this->z));
}

auto hrt::core::normal::operator+(const hrt::core::normal &v) const
    -> hrt::core::normal {

    return (hrt::core::normal(this->x + v.x, this->y + v.y, this->z + v.z));
}

auto hrt::core::normal::operator+=(const hrt::core::normal &v)
    -> hrt::core::normal& {

    this->x += v.x;
    this->y += v.y;
    this->z += v.z;
    return *this;
}

auto hrt::core::normal::operator-(const hrt::core::normal &v) const
    -> hrt::core::normal {

    return (hrt::core::normal(this->x - v.x, this->y - v.y, this->z - v.z));
}

auto hrt::core::normal::operator-=(const hrt::core::normal &v)
    -> hrt::core::normal& {

    this->x -= v.x;
    this->y -= v.y;
    this->z -= v.z;
    return *this;
}

auto hrt::core::normal::operator*(float f) const -> hrt::core::normal {

    return (hrt::core::normal(this->x * f, this->y * f, this->z * f));
}

auto hrt::core::normal::operator*=(float f) -> hrt::core::normal& {

    this->x *= f;
    this->y *= f;
    this->z *= f;
    return *this;
}

auto hrt::core::normal::operator/(float f) const -> hrt::core::normal {

    if(almost_equal_relative(f, 0, pow(10, -6))) {
        printf("SEVERE: normal: Tried to scale-by-reciprocal with a "
               "Zero: f=%f, x=%f, y=%f, z=%f ", f, x, y, z);
    }

    float inverse = 1.0f/f;

    return (hrt::core::normal(this->x * inverse,
                              this->y * inverse,
                              this->z * inverse));
}

auto hrt::core::normal::operator/=(float f) -> hrt::core::normal& {

    if(almost_equal_relative(f, 0, pow(10, -6))) {
        printf("SEVERE: normal: Tried to scale-assign-by-reciprocal with a "
               "Zero: f=%f, x=%f, y=%f, z=%f ", f, x, y, z);
    }

    float inverse = 1.0f/f;

    this->x *= inverse;
    this->y *= inverse;
    this->z *= inverse;
    return *this;
}

auto hrt::core::normal::operator[] (const std::size_t i) const -> float {

    if(i >= NUM_DIMENSIONS) {
        printf("SEVERE: normal: tried to get normal component greater"
               "than the number of dimensions (%i)", NUM_DIMENSIONS);
    }

    /* NOT GUARANTEED PORTABLE! */
    /* TODO: Test this */
    return (&x)[i];
}

auto hrt::core::normal::operator[] (const std::size_t i) -> float& {

    if(i >= NUM_DIMENSIONS) {
        printf("SEVERE: normal: tried to set normal component greater"
               "than the number of dimensions (%i)", NUM_DIMENSIONS);
    }

    /* NOT GUARANTEED PORTABLE! */
    /* TODO: Test this */
    return (&x)[i];
}
