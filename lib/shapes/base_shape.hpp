/*! Shape header for Hershal Bhave's hrt renderer */
/*! All shapes are defined in their own coordinate space */

#include <memory>
#include <vector>

#include "../core/bounding_box.hpp"
#include "../core/ray.hpp"
#include "../core/transform.hpp"
#include "../core/differential_geometry.hpp"

namespace hrt {
    namespace shapes {
        class base_shape {
        public:

            /*! \brief The object-to-world transform.
              This describes the mapping from object space to world space
            */
            const hrt::core::transform *object_to_world;

            /*! \brief The world-to-object transform.
              This describes the mapping from world space to object space
            */
            const hrt::core::transform *world_to_object;

            /*! \brief Reverse the surface normal.
              This orients the shape; the direction of the surface normal
              determines what part of the shape is supposed to be "inside" and
              what is "outside".
            */
            const bool reverse_normals;

            /*! \brief TODO I have no idea why this is here. */
            const bool transform_swaps_handedness;

            /*! \brief TODO I have no idea why this is here. */
            const size_t shape_id;

            /*! \brief TODO I have no idea why this is here. */
            static size_t next_shape_id;

            base_shape(hrt::core::transform *o_w, hrt::core::transform *w_o, bool reverse)
                : object_to_world(o_w)
                , world_to_object(w_o)
                , reverse_normals(reverse)
                , transform_swaps_handedness(o_w->swaps_handedness())
                , shape_id(next_shape_id++) { }

            /*! \brief Get the bounding box in the shape's object space. */
            virtual auto object_bound() const -> hrt::core::bounding_box = 0;

            /*! \brief Get the bounding box in the shape's world space. */
            auto world_bound() const -> hrt::core::bounding_box;

            /*! \brief Returns if this shape can compute its own ray
              intersections. The default shape can compute ray intersections,
              but not all shapes may do so. This method accounts for this so
              only shapes which have the capability of computing their own ray
              intersections. */
            auto can_intersect() const -> bool;

            /*! \brief Break the current shape up into refinable shapes. This
              method is only called if the shape is not directly
              ray-intersectable and requires further "refinement". This
              method breaks up this shape into a vector of subshapes which
              may or may not be able to calculate its own ray
              intersections. In that case, the nonintersectable shapes would
              have to be able to refine themselves further (recursively)
              until they breaks into atomic subshapes which are
              intersectable. Since a normal shape is intersectable, this stub
              does nothing. */
            auto refine(std::vector<hrt::shapes::base_shape*> &refined) const -> void;

            /*! \brief Returns the geometric information about a single
              ray-shape intersection corresponding to the first
              intersection.

              \param r The world-space ray to compute the intersection against
              \param t_hit
              \param rap_epsilon The maximum error in the intersection
              calculation
              \param dg Contains the information about the intersection,
              such as the local geometric properties of the surface
            */
            auto intersect(const hrt::core::ray &r, float *t_hit,
                           float *ray_epsilon,
                           hrt::core::differential_geometry *dg) const -> bool;

            /*! \brief Returns if a ray can intersect with the shape. This can be
              a more optimized version of intersect which only calculates if
              the ray hits. No geometric information need be returned
              here.

              \param r The world-space ray to determine the intersection
              against
            */
            auto intersectp(const hrt::core::ray &r) const -> bool;

            /* \brief Returns the surface area of the shape in object
               space. This is useful when using shapes as light sources.
            */
            auto surface_area() const -> float;

        private:

        };
    }
}
