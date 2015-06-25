#ifndef HRT_CORE_COMMON_MATRICES_HPP
#define HRT_CORE_COMMON_MATRICES_HPP

friend transform translate(float x, float y, float z) {

    transform t = transform();

    t.mat[0][3] = x;
    t.mat[1][3] = y;
    t.mat[2][3] = z;
    t.mat_inv[0][3] = -x;
    t.mat_inv[1][3] = -y;
    t.mat_inv[2][3] = -z;

    return t;
}

friend transform scale(float x, float y, float z) {

    transform t = transform();
    t.mat[0][0] = x;
    t.mat[1][1] = y;
    t.mat[2][2] = z;
    t.mat_inv[0][0] = 1.f/x;
    t.mat_inv[1][1] = 1.f/y;
    t.mat_inv[2][2] = 1.f/z;
    return t;
}

friend transform rotate_x(float rads) {

    float sin_tmp = sinf(rads);
    float cos_tmp = cosf(rads);
    transform t = transform();
    t.mat[1][1] = cos_tmp;
    t.mat[1][2] = -sin_tmp;
    t.mat[2][1] = sin_tmp;
    t.mat[2][2] = cos_tmp;
    t.mat_inv[1][1] = cos_tmp;
    t.mat_inv[1][2] = sin_tmp;
    t.mat_inv[2][1] = -sin_tmp;
    t.mat_inv[2][2] = cos_tmp;
    return t;
}

friend transform rotate_y(float rads) {

    float sin_tmp = sinf(rads);
    float cos_tmp = cosf(rads);
    transform t = transform();
    t.mat[0][0] = cos_tmp;
    t.mat[0][2] = sin_tmp;
    t.mat[2][0] = -sin_tmp;
    t.mat[2][2] = cos_tmp;
    t.mat_inv[0][0] = cos_tmp;
    t.mat_inv[0][2] = -sin_tmp;
    t.mat_inv[2][0] = sin_tmp;
    t.mat_inv[2][2] = cos_tmp;
    return t;
}
friend transform rotate_z(float rads) {

    float sin_tmp = sinf(rads);
    float cos_tmp = cosf(rads);
    transform t = transform();
    t.mat[0][0] = cos_tmp;
    t.mat[0][1] = -sin_tmp;
    t.mat[1][0] = sin_tmp;
    t.mat[1][1] = cos_tmp;
    t.mat_inv[0][0] = cos_tmp;
    t.mat_inv[0][1] = sin_tmp;
    t.mat_inv[1][0] = -sin_tmp;
    t.mat_inv[1][1] = cos_tmp;
    return t;
}
#endif  /* HRT_CORE_COMMON_MATRICES_HPP */
