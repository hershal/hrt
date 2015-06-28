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

friend transform look_at(const point *position, const point* look_at, const vector* y_dir) {

  float m[4][4];
  m[0][3] = position->x;
  m[1][3] = position->y;
  m[2][3] = position->z;
  m[3][3] = 1;

  /* direction from look_at to position */
  vector dir = geometry::normalize((*look_at - *position));

  vector left = geometry::normalize(geometry::cross(geometry::normalize(*y_dir), dir));
  vector new_y_dir = geometry::cross(dir, left);

  m[0][0] = left.x;
  m[0][1] = left.y;
  m[0][2] = left.z;
  m[0][3] = 0;
  m[1][0] = new_y_dir.x;
  m[1][1] = new_y_dir.y;
  m[1][2] = new_y_dir.z;
  m[1][3] = 0;
  m[2][0] = dir.x;
  m[2][1] = dir.y;
  m[2][2] = dir.z;
  m[2][3] = 0;

  return transform(m);
}

#endif  /* HRT_CORE_COMMON_MATRICES_HPP */
