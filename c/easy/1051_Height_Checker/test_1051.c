#include "gtest/gtest.h"

extern int heightChecker(int* heights, int heightsSize);

TEST(heightCheckerTest, test1) {
    int heights[] = {1,1,4,2,1,3};
    int heightsSize = sizeof(heights)/sizeof(heights[0]);
    int ans = heightChecker(heights, heightsSize);
    EXPECT_EQ(ans, 3);
}

TEST(heightCheckerTest, test2) {
    int heights[] = {5,1,2,3,4};
    int heightsSize = sizeof(heights)/sizeof(heights[0]);
    int ans = heightChecker(heights, heightsSize);
    EXPECT_EQ(ans, 5);
}

TEST(heightCheckerTest, test3) {
    int heights[] = {1,2,3,4,5};
    int heightsSize = sizeof(heights)/sizeof(heights[0]);
    int ans = heightChecker(heights, heightsSize);
    EXPECT_EQ(ans, 0);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}