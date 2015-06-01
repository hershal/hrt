/*! Point header for Hershal Bhave's hrt renderer */

#ifndef HRT_CORE_POINT_HPP
#define HRT_CORE_POINT_HPP

#include <cmath>
#include <cstdio>

#include "vector.hpp"

namespace hrt {
    namespace core {

        class vector;

        class point {
        public:
            point() { this->x = 0; this->y = 0; this->z = 0; }
            point(float x, float y, float z) : x(x), y(y), z(z) { }
            point(float f) : x(f), y(f), z(f) { }
            point(point* p) : x(p->x), y(p->y), z(p->z) { }

            /*! \brief Obtain the point offset by a vector */
            auto operator+(const hrt::core::vector &v) const -> point;

            /*! \brief Offset this point by a vector */
            auto operator+=(const hrt::core::vector &v) -> point&;

            /*! \brief Obtain the vector between this and another point */
            auto operator-(const hrt::core::point &p) const -> vector;

            /*! \brief Obtain the point offset by a vector */
            auto operator-(const hrt::core::vector &v) const -> point;

            /*! \brief Offset this point by a vector */
            auto operator-=(const hrt::core::vector &v) -> point&;

            /* --- Other point utility operators --- */

            /*! \brief point equality operator */
            auto operator= (const hrt::core::point &v) -> point&;

            /*! \brief point addition operator. */
            auto operator+(const hrt::core::point &v) const -> point;

            /*! \brief point accumulate operator. */
            auto operator+=(const hrt::core::point &v) -> point&;

            /*! \brief point scale operator. */
            auto operator*(float f) const -> point;

            /*! \brief point scale-assign operator. */
            auto operator*=(float f) -> point&;

            /*! \brief point get-value operator. */
            auto operator[] (const std::size_t i) const -> float;

            /*! \brief point set-value operator. */
            auto operator[] (const std::size_t i) -> float&;

            /* --- Friend utility functions --- */
            /*! \brief Get the distance between two points */
            friend auto distance(const point* p1, const point* p2) -> float;

            float x, y, z;
        };
    }
}

#endif /* HRT_CORE_POINT_HPP */
