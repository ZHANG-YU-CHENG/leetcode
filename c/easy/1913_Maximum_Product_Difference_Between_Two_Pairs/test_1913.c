#include "gtest/gtest.h"

extern int maxProductDifference(int* nums, int numsSize);

TEST(maxProductDifferenceTest, test1) {
    int nums[] = {5,6,2,7,4};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int ans = maxProductDifference(nums, numsSize);
    EXPECT_EQ(ans, 34);
}

TEST(maxProductDifferenceTest, test2) {
    int nums[] = {4,2,5,9,7,4,8};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int ans = maxProductDifference(nums, numsSize);
    EXPECT_EQ(ans, 64);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}