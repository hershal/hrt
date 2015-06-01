set (core-src bounding_box.cpp normal.cpp point.cpp vector.cpp)

include_directories("../")

add_library(core ${core-src})
