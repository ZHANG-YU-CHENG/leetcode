#include "gtest/gtest.h"

extern int arrayPairSum(int* nums, int numsSize);

TEST(arrayPairSumTest, test1) {
    int nums[] = {1,4,3,2};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int ans = arrayPairSum(nums, numsSize);
    EXPECT_EQ(ans, 4);
}

TEST(arrayPairSumTest, test2) {
    int nums[] = {6,2,6,5,1,2};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int ans = arrayPairSum(nums, numsSize);
    EXPECT_EQ(ans, 9);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}