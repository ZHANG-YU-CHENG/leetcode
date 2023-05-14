#include "gtest/gtest.h"

extern int countKDifference(int* nums, int numsSize, int k);

TEST(countKDifferenceTest, test1) {
    int nums[] = {1,2,2,1};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int k = 1;
    int ans = countKDifference(nums, numsSize, k);
    EXPECT_EQ(ans, 4);
}

TEST(countKDifferenceTest, test2) {
    int nums[] = {1,3};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int k = 3;
    int ans = countKDifference(nums, numsSize, k);
    EXPECT_EQ(ans, 0);
}

TEST(countKDifferenceTest, test3) {
    int nums[] = {3,2,1,5,4};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int k = 2;
    int ans = countKDifference(nums, numsSize, k);
    EXPECT_EQ(ans, 3);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}