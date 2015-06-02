/*! Transform header for Hershal Bhave's hrt renderer */

#ifndef HRT_CORE_TRANSFORM_HPP
#define HRT_CORE_TRANSFORM_HPP

#include <cmath>

namespace hrt {
    namespace core {

        class transform {
        public:
            transform(const float m[4][4]) {
                (void) m;
                (void) mat;
                (void) mat_inv;
            }
            transform(const float m[4][4], const float m_inv[4][4]) {
                (void) m;
                (void) m_inv;
                (void) mat;
                (void) mat_inv;
            }

            bool swaps_handedness(void);

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
