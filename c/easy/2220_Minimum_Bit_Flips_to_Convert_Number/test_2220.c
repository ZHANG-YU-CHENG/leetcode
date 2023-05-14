#include "gtest/gtest.h"

extern int minBitFlips(int start, int goal);

TEST(minBitFlipsTest, test1) {
    int start = 10;
    int goal = 7;
    int ans = minBitFlips(start, goal);
    EXPECT_EQ(ans, 3);
}

TEST(minBitFlipsTest, test2) {
    int start = 3;
    int goal = 4;
    int ans = minBitFlips(start, goal);
    EXPECT_EQ(ans, 3);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}