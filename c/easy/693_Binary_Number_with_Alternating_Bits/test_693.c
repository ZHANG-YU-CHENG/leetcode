#include "gtest/gtest.h"

extern bool hasAlternatingBits(int n);

TEST(hasAlternatingBitsTest, test1) {
    int n = 5;
    bool ans = hasAlternatingBits(n);
    EXPECT_TRUE(ans);
}

TEST(hasAlternatingBitsTest, test2) {
    int n = 7;
    bool ans = hasAlternatingBits(n);
    EXPECT_FALSE(ans);
}

TEST(hasAlternatingBitsTest, test3) {
    int n = 11;
    bool ans = hasAlternatingBits(n);
    EXPECT_FALSE(ans);
}

TEST(hasAlternatingBitsTest, test4) {
    int n = 4;
    bool ans = hasAlternatingBits(n);
    EXPECT_FALSE(ans);
}

TEST(hasAlternatingBitsTest, test5) {
    int n = 10;
    bool ans = hasAlternatingBits(n);
    EXPECT_TRUE(ans);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}