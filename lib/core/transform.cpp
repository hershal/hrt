/*! Point implementation for Hershal Bhave's hrt renderer */

#include "transform.hpp"

friend auto hrt::core::transform::inverse(const hrt::core::transform* t)
    -> hrt::core::transform {
    return hrt::core::transform(t->mat_inv, t->mat);
}
