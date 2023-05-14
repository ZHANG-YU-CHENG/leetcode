#include "gtest/gtest.h"

extern int subsetXORSum(int* nums, int numsSize);

TEST(subsetXORSumTest, test1) {
    int nums[] = {1,3};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int ans = subsetXORSum(nums, numsSize);
    EXPECT_EQ(ans, 6);
}

TEST(subsetXORSumTest, test2) {
    int nums[] = {5,1,6};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int ans = subsetXORSum(nums, numsSize);
    EXPECT_EQ(ans, 28);
}

TEST(subsetXORSumTest, test3) {
    int nums[] = {3,4,5,6,7,8};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int ans = subsetXORSum(nums, numsSize);
    EXPECT_EQ(ans, 480);
}


int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}