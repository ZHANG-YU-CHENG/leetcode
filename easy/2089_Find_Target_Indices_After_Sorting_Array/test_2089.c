#include "gtest/gtest.h"

extern int* targetIndices(int* nums, int numsSize, int target, int* returnSize);

TEST(targetIndicesTest, test1) {
    int nums[] = {1,2,5,2,3};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int target = 2;
    int returnSize;
    int* ans = targetIndices(nums, numsSize, target, &returnSize);

    int expect[] = {1,2};
    for(int i=0; i<returnSize; ++i)
    {
        EXPECT_EQ(ans[i], expect[i]);
    }
    if(ans) free(ans);
}

TEST(targetIndicesTest, test2) {
    int nums[] = {1,2,5,2,3};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int target = 3;
    int returnSize;
    int* ans = targetIndices(nums, numsSize, target, &returnSize);

    int expect[] = {3};
    for(int i=0; i<returnSize; ++i)
    {
        EXPECT_EQ(ans[i], expect[i]);
    }
    if(ans) free(ans);
}

TEST(targetIndicesTest, test3) {
    int nums[] = {1,2,5,2,3};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int target = 5;
    int returnSize;
    int* ans = targetIndices(nums, numsSize, target, &returnSize);

    int expect[] = {4};
    for(int i=0; i<returnSize; ++i)
    {
        EXPECT_EQ(ans[i], expect[i]);
    }
    if(ans) free(ans);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}