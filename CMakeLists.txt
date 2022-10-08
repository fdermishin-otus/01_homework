cmake_minimum_required(VERSION 3.21)

set(PATCH_VERSION "1" CACHE STRING "Patch version")
project(01_homework VERSION 0.0.${PATCH_VERSION})

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
        RUNTIME DESTINATION /usr/bin
)

set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_CONTACT fdermishin-otus@users.noreply.github.com)
include(CPack)

message("CPACK_DEBIAN_PACKAGE_NAME: " ${CPACK_DEBIAN_PACKAGE_NAME})
message("CPACK_PACKAGE_FILE_NAME: " ${CPACK_PACKAGE_FILE_NAME})
file(RENAME ${PROJECT_BINARY_DIR}/${CPACK_PACKAGE_FILE_NAME}.deb ${PROJECT_BINARY_DIR}/release/${CPACK_PACKAGE_FILE_NAME}.deb)
