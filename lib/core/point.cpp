/*! Point implementation for Hershal Bhave's hrt renderer */

#include "point.hpp"

auto hrt::core::point::operator+(const hrt::core::vector &v) const -> point {
    return point(this->x + v.x, this->y + v.y, this->z + v.z);
}

auto hrt::core::point::operator+=(const hrt::core::vector &v) -> point& {
    this->x += v.x;
    this->y += v.y;
    this->z += v.z;
    return *this;
}

auto hrt::core::point::operator-(const hrt::core::point &p) const -> hrt::core::vector {
    return vector(this->x - p.x, this->y - p.y, this->z - p.z);
}

auto hrt::core::point::operator-(const hrt::core::vector &v) const -> hrt::core::point {
    return point(this->x - v.x, this->y - v.y, this->z - v.z);
}

                                                                                                                                                   auto hrt::core::point::operator-=(const hrt::core::vector &v) -> hrt::core::point& {
    this->x -= v.x;
    this->y -= v.y;
    this->z -= v.z;
    return *this;
}

auto hrt::core::point::operator= (const hrt::core::point& v) -> hrt::core::point& {
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
    return *this;
}

auto hrt::core::point::operator+(const hrt::core::point &v) const -> hrt::core::point {
    return (point(this->x + v.x,
                  this->y + v.y,
                  this->z + v.z));
}

auto hrt::core::point::operator+=(const hrt::core::point &v) -> hrt::core::point& {
    this->x += v.x;
    this->y += v.y;
    this->z += v.z;
    return *this;
}

auto hrt::core::point::operator*(float f) const -> hrt::core::point {
    return (point(this->x * f, this->y * f, this->z * f));
}

auto hrt::core::point::operator*=(float f) -> hrt::core::point& {
    this->x *= f;
    this->y *= f;
    this->z *= f;
    return *this;
}

auto hrt::core::point::operator[] (const std::size_t i) const -> float {
    if(i >= NUM_DIMENSIONS) {
        printf("SEVERE: point: tried to get point component greater"
               "than the number of dimensions (%i): %lu", NUM_DIMENSIONS, i);
    }

    /* NOT GUARANTEED PORTABLE! */
    /* TODO: Test this */
    return (&x)[i];
}

auto hrt::core::point::operator[] (const std::size_t i) -> float& {
    if(i >= NUM_DIMENSIONS) {
        printf("SEVERE: point: tried to set point component greater"
               "than the number of dimensions (%i): %lu", NUM_DIMENSIONS, i);
    }

    /* NOT GUARANTEED PORTABLE! */
    /* TODO: Test this */
    return (&x)[i];
}

auto distance(const hrt::core::point* p1,
              const hrt::core::point* p2)
    -> float {

    float xx = p1->x - p2->x;
    float yy = p1->y - p2->y;
    float zz = p1->z - p2->z;

    return sqrt(xx*xx + yy*yy + zz*zz);
}
