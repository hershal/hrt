cmake_minimum_required(VERSION 2.8.7)

enable_testing()

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
else(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

option(PROFILE "Enable profiling build options" OFF)
option(PEDANTIC "Enable pedantic and Wall" ON)
option(COLOR "Enable colorized output (clang-only)" ON)

if(PROFILE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage -g -O0")
endif()

if(PEDANTIC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wall -Wextra -Werror")
endif()

if(NOT COLOR)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-color-diagnostics")
endif()

add_subdirectory(lib)
add_subdirectory(tests)
add_subdirectory(prototyping)