#include "gtest/gtest.h"

extern int findMin(int* nums, int numsSize);

TEST(findMinTest, test1) {
    int nums[] = {3,4,5,1,2};
    int numsSize = 5;
    int out = findMin(nums, numsSize);
    EXPECT_EQ(1, out);
}

TEST(findMinTest, test2) {
    int nums[] = {4,5,6,7,0,1,2};
    int numsSize = 7;
    int out = findMin(nums, numsSize);
    EXPECT_EQ(0, out);
}

TEST(findMinTest, test3) {
    int nums[] = {11,13,15,17};
    int numsSize = 4;
    int out = findMin(nums, numsSize);
    EXPECT_EQ(11, out);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}