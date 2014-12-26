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

auto operator= (const point& v) -> point& {
    this.x = v.x;
    this.y = v.y;
    this.z = v.z;
    return *this;
}

auto operator+(const point &v) const -> point {
    return (point(this.x + v.x,
                  this.y + v.y,
                  this.z + v.z));
}

auto operator+=(const point &v) -> point& {
    this.x += v.x;
    this.y += v.y;
    this.z += v.z;
    return *this;
}

auto operator*(float f) const -> point {
    return (point(this.x * f,
                  this.y * f,
                  this.z * f));
}

auto operator*=(float &v) -> point& {
    this.x *= f;
    this.y *= f;
    this.z *= f;
    return *this;
}

