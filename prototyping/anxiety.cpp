#include "../lib/core/ray.hpp"
#include "../lib/core/vector.hpp"
#include "../lib/core/transform.hpp"
#include "../lib/utility/utility_functions.hpp"
#include "../lib/core/geometry.hpp"

#include "GraphicsMagick/Magick++.h"

#include <cmath>
#include <memory>

int main() {

    using namespace hrt::core;

    /* user-adjustable constants */
    /* 1cm = 1.f */
    size_t xres = 100;
    size_t yres = 100;
    float fov_degrees = 75.f;
    float camera_radius = 5.f;

    /* computed constants */
    float fov = to_radians(fov_degrees);
    float fovmin = -fov/2;
    float fovmax = fov/2;

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

    Magick::InitializeMagick(0);
    Magick::Image img("100x100", "white");
    Magick::Color hitcolor("black");
    /* float** film = (float**)malloc(xres*yres*sizeof(float)); */

    vector camera_to_sphere(sphere_origin - camera_origin);

    for (size_t i=0; i<xres; ++i) {
        for (size_t j=0; j<yres; ++j) {

            /* camera's radius is specified, meaning the film is
               on the origin in camera-space and the lens is the
               radius away. */
            /* compute angle into the scene */

            /* this is a pinhole camera */
            float camera_x_rotate = linear_interpolate((float)i/xres,fovmin,fovmax);
            float camera_y_rotate = linear_interpolate((float)j/yres,fovmin,fovmax);
            vector camera_at_world = geometry::normalize(vector(camera_x_rotate, camera_y_rotate, 1));

            ray r(camera_origin, camera_at_world);

            /* testing for sphere intersection */
            float t_ca = geometry::dot(camera_to_sphere, r.direction);
            float d = sqrtf(camera_to_sphere.normsq() - t_ca*t_ca);

            if (d < sphere_r) {
                img.pixelColor(i, j, hitcolor);
                /* film[i][j] = 1.f; */
            } else {
                /* film[i][j] = 0.f; */
            }

            (void) light_dir;
            (void) camera_dir;
            (void) sphere_r;
            (void) camera_radius;
        }
    }

    img.write("anxiety.png");
    return 0;
}
