#include "gtest/gtest.h"

extern bool isUgly(int n);

TEST(isUglyTest, test1) {
    int n = 6;
    bool out = isUgly(n);
    EXPECT_TRUE(out);
}

TEST(isUglyTest, test2) {
    int n = 1;
    bool out = isUgly(n);
    EXPECT_TRUE(out);
}

TEST(isUglyTest, test3) {
    int n = 14;
    bool out = isUgly(n);
    EXPECT_FALSE(out);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}