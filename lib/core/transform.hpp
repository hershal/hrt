/*! Transform header for Hershal Bhave's hrt renderer */

#ifndef HRT_CORE_TRANSFORM_HPP
#define HRT_CORE_TRANSFORM_HPP

#include <cmath>
#include "core/vector.hpp"
#include "core/point.hpp"
#include "core/geometry.hpp"
#include "utility/matrix4x4.hpp"

namespace hrt {
    namespace core {

        class transform {
        public:
            transform() {
                hrt::matrix4x4::identity(mat);
                hrt::matrix4x4::identity(mat_inv);
            }

            transform(const float m[4][4]) {
                hrt::matrix4x4::copy(m, mat);
                hrt::matrix4x4::inverse(m, mat_inv);
            }

            transform(const float m[4][4], const float m_inv[4][4]) {
                hrt::matrix4x4::copy(m, mat);
                hrt::matrix4x4::copy(m_inv, mat_inv);
            }

            #include "common_matrices.hpp"

            bool swaps_handedness(void);

            auto inverse(const transform* t) -> transform;

            auto rotate(float rads, const vector *axis) -> transform;

        private:

            /*! \brief The transformation matrix.

              Keep this in row-major order, i.e. mat[i][j] corresponds
              to $mat_{i,j}$.
             */
            float mat[4][4];

            /*! \brief The inverted transformation matrix.

              Keep this in row-major order, i.e. mat[i][j] corresponds
              to $mat_{i,j}$.
             */
            float mat_inv[4][4];
        };
    }
}

#endif /* HRT_CORE_TRANSFORM_HPP */
