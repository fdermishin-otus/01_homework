cmake_minimum_required(VERSION 3.21)
project(01_homework)

set(CMAKE_CXX_STANDARD 17)

message(VERSION=${VERSION})
configure_file(version.hpp.in include/version.hpp @ONLY)

add_executable(01_homework src/main.cpp)

target_compile_features(01_homework PUBLIC cxx_std_17)

target_include_directories(01_homework PRIVATE ${PROJECT_BINARY_DIR}/include)

enable_testing()

if (BUILD_TESTING)
    add_subdirectory(test)
endif ()