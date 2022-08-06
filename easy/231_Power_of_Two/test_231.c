#include "gtest/gtest.h"

extern bool isPowerOfTwo(int n);

TEST(isPowerOfTwoTest, test1) {
    int n = 1;
    bool out = isPowerOfTwo(n);
    EXPECT_TRUE(out);
}

TEST(isPowerOfTwoTest, test2) {
    int n = 16;
    bool out = isPowerOfTwo(n);
    EXPECT_TRUE(out);
}

TEST(isPowerOfTwoTest, test3) {
    int n = 3;
    bool out = isPowerOfTwo(n);
    EXPECT_FALSE(out);
}

TEST(isPowerOfTwoTest, test4) {
    int n = 6;
    bool out = isPowerOfTwo(n);
    EXPECT_FALSE(out);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}