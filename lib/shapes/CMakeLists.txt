set (shapes-src base_shape.cpp sphere.cpp)
include_directories("../")
add_library(shapes ${shapes-src})
