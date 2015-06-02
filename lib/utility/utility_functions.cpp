#include "utility_functions.hpp"
#include <boost/assert.hpp>

auto clamp(float n, float lower, float upper) -> float {

    BOOST_ASSERT_MSG(lower < upper, "clamp low value >= upper value");
    return std::fmax(lower, std::fmin(n, upper));
}

auto linear_interpolate(float t, float v1, float v2) -> float {
    return (1.0f - t)*v1 + t*v2;
}

auto relative_error(float a, float b) -> float {
    return std::fabs((a - b)/b);
}

auto absolute_error(float a, float b) -> float {
    return std::fabs(a - b);
}

auto almost_equal_relative(float a, float b, float epsilon) -> bool {

    /* Remove a division-by-zero possibility */
    if (a == b) {
        return true;
    }

    /* We want to divide by the largest number to minimize roundoff error */
    float relerr;
    if (std::fabs(a) > std::fabs(b)) {
        relerr = relative_error(b, a);
    } else {
        relerr = relative_error(a, b);
    }

    if (relerr <= epsilon) {
        return true;
    }

    return false;
}

auto is_between_inc(int val, int low, int high) -> bool {
    return ((val >= low) && (val <= high));
}

auto is_between_exc(int val, int low, int high) -> bool {
    return ((val > low) && (val < high));
}
