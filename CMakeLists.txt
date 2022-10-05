cmake_minimum_required(VERSION 3.21)
project(01_homework)

set(CMAKE_CXX_STANDARD 17)

configure_file(version.hpp.in include/version.hpp)

include_directories(${CMAKE_CURRENT_BINARY_DIR}/include @ONLY)

add_executable(01_homework src/main.cpp)
