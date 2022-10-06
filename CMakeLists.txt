cmake_minimum_required(VERSION 3.21)
project(01_homework)

set(CMAKE_CXX_STANDARD 17)

message(VERSION=${VERSION})
configure_file(version.hpp.in include/version.hpp @ONLY)

add_executable(${PROJECT_NAME} src/main.cpp)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_BINARY_DIR}/include)

enable_testing()

if (BUILD_TESTING)
    add_subdirectory(test)
endif ()

install(
        TARGETS ${PROJECT_NAME}
)

SET(CPACK_GENERATOR "DEB")
#SET(CPACK_DEBIAN_PACKAGE_MAINTAINER)
INCLUDE(CPACK)