set (core-src bounding_box.cpp normal.cpp point.cpp vector.cpp)

include_directories("../utility")

add_library(core ${core-src})
