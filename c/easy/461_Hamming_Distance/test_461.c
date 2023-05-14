#include "gtest/gtest.h"

extern int hammingDistance(int x, int y);

TEST(hammingDistanceTest, test1) {
    int x = 1;
    int y = 4;
    int ans = hammingDistance(x, y);
    EXPECT_EQ(ans, 2);
}

TEST(hammingDistanceTest, test2) {
    int x = 3;
    int y = 1;
    int ans = hammingDistance(x, y);
    EXPECT_EQ(ans, 1);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}