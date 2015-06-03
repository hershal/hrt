#include "utility/matrix4x4.hpp"

static float identity_matrix[4][4] =
    {{1.f, 0.f, 0.f, 0.f},
     {0.f, 1.f, 0.f, 0.f},
     {0.f, 0.f, 1.f, 0.f},
     {0.f, 0.f, 0.f, 1.f}};

auto hrt::matrix4x4::eye(float m[4][4]) -> void {
    memcpy(m, identity_matrix, 16*sizeof(float));
}

auto hrt::matrix4x4::zero(float m[4][4]) -> void {
    float *f = (float*)(m);
    for (uint8_t i=0; i<16; ++i) {
        f[i] = 0.f;
    }
}

auto hrt::matrix4x4::copy(float src[4][4], float dst[4][4]) -> void {
    memcpy(dst, src, 16*sizeof(float));
}
