include_directories("../lib")

# anxiety
set(anxiety-srcs anxiety.cpp)
add_executable(anxiety ${anxiety-srcs})
target_link_libraries(anxiety core utility shapes "/usr/lib/libGraphicsMagick++.so")

# graphicsmagick
set(graphicsmagick-srcs graphicsmagick.cpp)
include_directories("/usr/include/GraphicsMagick")
add_executable(graphicsmagick ${graphicsmagick-srcs})
target_link_libraries(graphicsmagick "/usr/lib/libGraphicsMagick++.so")
