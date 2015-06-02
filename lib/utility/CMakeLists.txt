set (utility-src utility_functions.cpp matrix4x4.cpp)
include_directories("../")
add_library(utility ${utility-src})
