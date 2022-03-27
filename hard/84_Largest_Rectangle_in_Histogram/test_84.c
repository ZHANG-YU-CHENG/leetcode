#include "gtest/gtest.h"

extern int largestRectangleArea(int* heights, int heightsSize);

TEST(largestRectangleAreaTest, test1) {
    int heightsSize = 6;
    int heights[6] = {2,1,5,6,2,3};
    int out = largestRectangleArea(heights, heightsSize);
    EXPECT_EQ(10, out);
}

TEST(largestRectangleAreaTest, test2) {
    int heightsSize = 2;
    int heights[2] = {2,4};
    int out = largestRectangleArea(heights, heightsSize);
    EXPECT_EQ(4, out);
}

TEST(largestRectangleAreaTest, test3) {
    int heightsSize = 1;
    int heights[1] = {3};
    int out = largestRectangleArea(heights, heightsSize);
    EXPECT_EQ(3, out);
}

TEST(largestRectangleAreaTest, test4) {
    int heightsSize = 3;
    int heights[3] = {2,1,2};
    int out = largestRectangleArea(heights, heightsSize);
    EXPECT_EQ(3, out);
}

TEST(largestRectangleAreaTest, test5) {
    int heightsSize = 5;
    int heights[5] = {1,3,2,3,1};
    int out = largestRectangleArea(heights, heightsSize);
    EXPECT_EQ(6, out);
}

TEST(largestRectangleAreaTest, test6) {
    int heightsSize = 5;
    int heights[5] = {2,3,2,3,1};
    int out = largestRectangleArea(heights, heightsSize);
    EXPECT_EQ(8, out);
}

TEST(largestRectangleAreaTest, test7) {
    int heightsSize = 8;
    int heights[8] = {4,2,0,3,2,4,3,4};
    int out = largestRectangleArea(heights, heightsSize);
    EXPECT_EQ(10, out);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}