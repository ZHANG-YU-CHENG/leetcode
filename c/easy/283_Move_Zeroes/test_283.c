#include "gtest/gtest.h"

extern void moveZeroes(int* nums, int numsSize);

TEST(moveZeroesTest, test1) {
    int nums[] = {0,1,0,3,12};
    int ans[] = {1,3,12,0,0};
    int numsSize = 5;
    moveZeroes(nums, numsSize);
    for(int i=0; i<numsSize; ++i)
    {
        EXPECT_EQ(nums[i], ans[i]);
    }
}

TEST(moveZeroesTest, test2) {
    int nums[] = {0};
    int ans[] = {0};
    int numsSize = 1;
    moveZeroes(nums, numsSize);
    for(int i=0; i<numsSize; ++i)
    {
        EXPECT_EQ(nums[i], ans[i]);
    }
}

TEST(moveZeroesTest, test3) {
    int nums[] = {0,0,1};
    int ans[] = {1,0,0};
    int numsSize = 3;
    moveZeroes(nums, numsSize);
    for(int i=0; i<numsSize; ++i)
    {
        EXPECT_EQ(nums[i], ans[i]);
    }
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}