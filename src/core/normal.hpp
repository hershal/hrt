/*! Surface Normal header for Hershal Bhave's hrt renderer */

/*! A Surface Normal is a vector which is purpendicular to a surface
    at some position. Surface Normals are defined in terms of its
    relationship between the surface and itself. A Surface Normal is
    not necessarily normalized. */

#include <cmath>

class normal {
public:
    normal() { this.x = 0; this.y = 0; this.z = 0; }

    normal(float x, float y, float z)
        : x(x), y(y), z(z) {
        if (hasnan()) {
            printf("SEVERE: normal: Tried to construct a normal with a "
                   "NaN: x=%f, y=%f, z=%f ", x, y, z);
        }
    }

    explicit normal (const vector &n) : x(n.x), y(n.y), z(n.z) { }

    /*! \brief Returns if the normal has at least one not-a-number
      element. */
    auto hasnan() const -> bool;

    /* \brief Returns the 2-norm of this normal, squared */
    auto normsq() const -> float;

    /*! \brief Returns the 2-norm of this normal */
    auto norm() const -> float;

    /*! \brief normal equality operator */
    auto operator= (const normal& v) -> normal&;

    /*! \brief normal unary negation operator. */
    auto operator-() const -> normal;

    /*! \brief normal addition operator. */
    auto operator+(const normal &v) const -> normal;

    /*! \brief normal accumulate operator. */
    auto operator+=(const normal &v) -> normal&;

    /*! \brief normal subtraction operator. */
    auto operator-(const normal &v) const -> normal;

    /*! \brief normal reduce operator. */
    auto operator-=(const normal &v) -> normal&;

    /*! \brief normal scale operator. */
    auto operator*(const normal &v) const -> normal;

    /*! \brief normal scale-assign operator. */
    auto operator*=(const normal &v) -> normal&;

    /*! \brief normal scale-by-reciprocal operator. */
    auto operator/(const normal &v) const -> normal;

    /*! \brief normal scale-assign-by-reciprocal operator. */
    auto operator/=(const normal &v) -> normal&;

    /*! \brief normal get-value operator. */
    auto operator[] (const std::size_t i) const -> const float;

    /*! \brief normal set-value operator. */
    auto operator[] (const std::size_t i) -> float&;
    
    float x, y, z;
}
