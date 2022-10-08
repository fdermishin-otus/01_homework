#include <gtest/gtest.h>
#include "version.hpp"

TEST(VersionTest, IsValid) {
    EXPECT_GT(PROJECT_VERSION_PATCH, 0);
}
