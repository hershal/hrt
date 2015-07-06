include_directories("../lib")

# graphicsmagick
set(graphicsmagick-srcs graphicsmagick.cpp)
include_directories("/usr/include/GraphicsMagick")
add_executable(graphicsmagick ${graphicsmagick-srcs})
target_link_libraries(graphicsmagick "/usr/lib/libGraphicsMagick++.so")
