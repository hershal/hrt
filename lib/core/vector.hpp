/*! Vector header for Hershal Bhave's hrt renderer */

/* DO NOT use the std namespace as this name will conflict with that
   namespace */

#ifndef HRT_CORE_VECTOR_HPP
#define HRT_CORE_VECTOR_HPP

#include <cmath>
#include <cstdio>

#define NUM_DIMENSIONS 3

namespace hrt {
    namespace core {
        class vector {
        public:
            vector() { this->x = 0; this->y = 0; this->z = 0; }

            vector(float x, float y, float z)
                : x(x), y(y), z(z) {
                if (hasnan()) {
                    printf("SEVERE: vector: Tried to construct a vector with a "
                           "NaN: x=%f, y=%f, z=%f ", x, y, z);
                }
            }

            /* explicit vector (const normal &n) : x(n.x), y(n.y), z(n.z) { }; */

            /*! \brief Returns if the vector has at least one not-a-number
              element. */
            auto hasnan() const -> bool;

            /* \brief Returns the 2-norm of this vector, squared */
            auto normsq() const -> float;

            /*! \brief Returns the 2-norm of this vector */
            auto norm() const -> float;

            /*! \brief vector equality operator */
            auto operator= (const vector& v) -> vector&;

            /*! \brief vector unary negation operator. */
            auto operator-() const -> vector;

            /*! \brief vector addition operator. */
            auto operator+(const vector &v) const -> vector;

            /*! \brief vector accumulate operator. */
            auto operator+=(const vector &v) -> vector&;

            /*! \brief vector subtraction operator. */
            auto operator-(const vector &v) const -> vector;

            /*! \brief vector reduce operator. */
            auto operator-=(const vector &v) -> vector&;

            /*! \brief vector scale operator. */
            auto operator*(float f) const -> vector;

            /*! \brief vector scale-assign operator. */
            auto operator*=(float f) -> vector&;

            /*! \brief vector scale-by-reciprocal operator. */
            auto operator/(float f) const -> vector;

            /*! \brief vector scale-assign-by-reciprocal operator. */
            auto operator/=(float f) -> vector&;

            /*! \brief vector get-value operator. */
            auto operator[] (const std::size_t i) const -> float;

            /*! \brief vector set-value operator. */
            auto operator[] (const std::size_t i) -> float&;

            float x, y, z;
        };
    }
}
#endif /* HRT_CORE_VECTOR_HPP */
