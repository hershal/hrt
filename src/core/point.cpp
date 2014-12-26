/*! Point implementation for Hershal Bhave's hrt renderer */

#include "point.hpp"

auto point::operator+(const vector &v) const -> point {
    return point(this.x + v.x, this.y + v.y, this.z + v.z);
}

auto point::operator+=(const vector &v) -> point& {
    this.x += v.x;
    this.y += v.y;
    this.z += v.z;
    return *this;
}

auto point::operator-(const point &p) const -> vector {
    return vector(this.x - p.x, this.y - p.y, this.z - p.z);
}

auto point::operator-(const vector &v) const -> point {
    return point(this.x - v.x, this.y - v.y, this.z - v.z);
}

auto point::operator-=(const vector &v) -> point& {
    this.x -= v.x;
    this.y -= v.y;
    this.z -= v.z;
    return *this;
}

auto point::operator= (const point& v) -> point& {
    this.x = v.x;
    this.y = v.y;
    this.z = v.z;
    return *this;
}

auto point::operator+(const point &v) const -> point {
    return (point(this.x + v.x,
                  this.y + v.y,
                  this.z + v.z));
}

auto point::operator+=(const point &v) -> point& {
    this.x += v.x;
    this.y += v.y;
    this.z += v.z;
    return *this;
}

auto point::operator*(float f) const -> point {
    return (point(this.x * f,
                  this.y * f,
                  this.z * f));
}

auto point::operator*=(float &v) -> point& {
    this.x *= f;
    this.y *= f;
    this.z *= f;
    return *this;
}

auto point::operator[] (const std::size_t i) const -> const float {
    if(i >= NUM_DIMENSIONS) {
        printf("SEVERE: point: tried to get point component greater"
               "than the number of dimensions (%i)", NUM_DIMENSIONS);
    }

    /* NOT GUARANTEED PORTABLE! */
    /* TODO: Test this */
    return (&x)[i];
}

auto point::operator[] (const std::size_t i) -> float& {
    if(i >= NUM_DIMENSIONS) {
        printf("SEVERE: point: tried to set point component greater"
               "than the number of dimensions (%i)", NUM_DIMENSIONS);
    }

    /* NOT GUARANTEED PORTABLE! */
    /* TODO: Test this */
    return (&x)[i];
}
