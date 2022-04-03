#include "gtest/gtest.h"
#include <stdint.h>

extern int rangeBitwiseAnd(int left, int right);

TEST(rangeBitwiseAndTest, test1) {
    int left = 5;
    int right = 7;
    int out = rangeBitwiseAnd(left, right);
    EXPECT_EQ(4, out);
}

TEST(rangeBitwiseAndTest, test2) {
    int left = 0;
    int right = 0;
    int out = rangeBitwiseAnd(left, right);
    EXPECT_EQ(0, out);
}

TEST(rangeBitwiseAndTest, test3) {
    int left = 1;
    int right = 2147483647;
    int out = rangeBitwiseAnd(left, right);
    EXPECT_EQ(0, out);
}

TEST(rangeBitwiseAndTest, test4) {
    int left = 2;
    int right = 2;
    int out = rangeBitwiseAnd(left, right);
    EXPECT_EQ(2, out);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}