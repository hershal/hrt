set (core-src bounding_box.cpp normal.cpp point.cpp vector.cpp transform.cpp rgb_spectrum.cpp)

include_directories("../")

add_library(core ${core-src})
