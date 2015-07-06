#include "../lib/core/ray.hpp"
#include "../lib/core/vector.hpp"
#include "../lib/core/transform.hpp"
#include "../lib/utility/utility_functions.hpp"

#include "GraphicsMagick/Magick++.h"

#include <cmath>

int main() {

    using namespace hrt::core;

    /* user-adjustable constants */
    size_t xres = 100;
    size_t yres = 100;
    size_t numbounces = 3;
    float fov_degrees = 75.f;
    /* TODO: determine how the camera optics work */
    float camera_radius = 5.f;

    /* computed constants */
    float fov = fov_degrees*M_PI/180;
    float fovmax = -fov/2;
    float fovmin = fov/2;

    /* sphere */
    point sphere_origin(10.f, 5.f, 10.f);
    float sphere_r = 5.f;

    /* camera */
    point camera_origin(10.f, 10.f, 0.f);
    vector camera_dir = sphere_origin - camera_origin;

    /* light */
    point light_origin(10.f, 20.f, 10.f);
    vector light_dir = sphere_origin - light_origin;

    /* box enclosing the entire thing with extrema at 0 and 25 */
    /* this box is fully diffusive */

    for (size_t i=0; i<xres; ++i) {
        for (size_t j=0; j<yres; ++j) {
            for (size_t k=0; k<numbounces; ++k) {

                /* compute angle into the scene */

            }
        }
    }
}
