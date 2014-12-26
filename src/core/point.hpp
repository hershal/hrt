/*! Point header for Hershal Bhave's hrt renderer */

#include <cmath>

class point {
public:
    point() { this.x = 0; this.y = 0; this.z = 0; }
    point(float x, float y, float z)
        : x(x), y(y), z(z) { }

    /*! \brief Obtain the point offset by a vector */
    auto operator+(const vector &v) const -> point;

    /*! \brief Offset this point by a vector */
    auto operator+=(const vector &v) -> point&;

    /*! \brief Obtain the vector between this and another point */
    auto operator-(const point &p) const -> vector;

    /*! \brief Obtain the point offset by a vector */
    auto operator-(const vector &v) const -> point;

    /*! \brief Offset this point by a vector */
    auto operator-=(const vector &v) -> point&;

    /* --- Other point utility operators --- */

    /*! \brief point equality operator */
    auto operator= (const point& v) -> point&

    /*! \brief point addition operator. */
    auto operator+(const point &v) const -> point;

    /*! \brief point accumulate operator. */
    auto operator+=(const point &v) -> point&;

    /*! \brief point scale operator. */
    auto operator*(const point &v) const -> point;

    /*! \brief point scale-assign operator. */
    auto operator*=(const point &v) -> point&;

    /*! \brief point get-value operator. */
    auto operator[] (const std::size_t i) const -> const float;

    /*! \brief point set-value operator. */
    auto operator[] (const std::size_t i) -> float&;

    float x, y, z;
}
