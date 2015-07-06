#include "rgb_spectrum.hpp"

auto hrt::core::rgb_spectrum::to_rgb(float *rgb) -> void {
    rgb[0] = c[0];
    rgb[1] = c[1];
    rgb[2] = c[2];
}
