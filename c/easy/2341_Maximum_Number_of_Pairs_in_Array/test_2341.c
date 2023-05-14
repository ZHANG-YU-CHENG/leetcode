#include "gtest/gtest.h"

extern int* numberOfPairs(int* nums, int numsSize, int* returnSize);

TEST(numberOfPairsTest, test1) {
    int nums[] = {1,3,2,1,3,2,2};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int returnSize;
    int* ans = numberOfPairs(nums, numsSize, &returnSize);
    EXPECT_EQ(returnSize, 2);
    EXPECT_EQ(ans[0], 3);
    EXPECT_EQ(ans[1], 1);
    if(ans) free(ans);
}

TEST(numberOfPairsTest, test2) {
    int nums[] = {1,1};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int returnSize;
    int* ans = numberOfPairs(nums, numsSize, &returnSize);
    EXPECT_EQ(returnSize, 2);
    EXPECT_EQ(ans[0], 1);
    EXPECT_EQ(ans[1], 0);
    if(ans) free(ans);
}

TEST(numberOfPairsTest, test3) {
    int nums[] = {0};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int returnSize;
    int* ans = numberOfPairs(nums, numsSize, &returnSize);
    EXPECT_EQ(returnSize, 2);
    EXPECT_EQ(ans[0], 0);
    EXPECT_EQ(ans[1], 1);
    if(ans) free(ans);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}