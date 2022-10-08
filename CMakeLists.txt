cmake_minimum_required(VERSION 3.21)

set(PATCH_VERSION "1" CACHE STRING "Patch version")
project(helloworld_cli VERSION 0.0.${PATCH_VERSION})

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

configure_file(version.hpp.in include/version.hpp @ONLY)

add_executable(${PROJECT_NAME} src/main.cpp)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_BINARY_DIR}/include)

add_executable(${PROJECT_NAME}_test test/version_test.cpp)
target_link_libraries(${PROJECT_NAME}_test GTest::gtest_main)
target_include_directories(${PROJECT_NAME}_test PRIVATE ${PROJECT_BINARY_DIR}/include)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}_test)

enable_testing()

if (BUILD_TESTING)
    add_subdirectory(test)
endif ()

install(
        TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION /usr/bin
)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_CONTACT fdermishin-otus@users.noreply.github.com)
SET(CPACK_OUTPUT_FILE_PREFIX ${PROJECT_SOURCE_DIR}/release)
include(CPack)
