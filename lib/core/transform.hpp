/*! Transform header for Hershal Bhave's hrt renderer */

#ifndef HRT_CORE_TRANSFORM_HPP
#define HRT_CORE_TRANSFORM_HPP

#include <cmath>
#include "utility/matrix4x4.hpp"

namespace hrt {
    namespace core {

        class transform {
        public:
            transform() {
                hrt::matrix4x4::eye(mat);
                hrt::matrix4x4::eye(mat_inv);
            }

            transform(const float m[4][4]) {
                hrt::matrix4x4::copy(m, mat);
                hrt::matrix4x4::inverse(m, mat_inv);
            }

            transform(const float m[4][4], const float m_inv[4][4]) {
                hrt::matrix4x4::copy(m, mat);
                hrt::matrix4x4::copy(m_inv, mat_inv);
            }

            bool swaps_handedness(void);

            friend auto inverse(const transform* t) -> hrt::core::transform;

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
