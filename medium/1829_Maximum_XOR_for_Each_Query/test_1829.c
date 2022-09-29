#include "gtest/gtest.h"

extern int* getMaximumXor(int* nums, int numsSize, int maximumBit, int* returnSize);

TEST(getMaximumXorTest, test1) {
    int nums[] = {0,1,1,3};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int maximumBit = 2;
    int returnSize;
    int* ans = getMaximumXor(nums, numsSize, maximumBit, &returnSize);
    int expect[] = {0,3,2,3};
    EXPECT_EQ(returnSize, numsSize);
    for(int i=0; i<returnSize; ++i)
        EXPECT_EQ(ans[i], expect[i]);
}

TEST(getMaximumXorTest, test2) {
    int nums[] = {2,3,4,7};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int maximumBit = 3;
    int returnSize;
    int* ans = getMaximumXor(nums, numsSize, maximumBit, &returnSize);
    int expect[] = {5,2,6,5};
    EXPECT_EQ(returnSize, numsSize);
    for(int i=0; i<returnSize; ++i)
        EXPECT_EQ(ans[i], expect[i]);
}

TEST(getMaximumXorTest, test3) {
    int nums[] = {0,1,2,2,5,7};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int maximumBit = 3;
    int returnSize;
    int* ans = getMaximumXor(nums, numsSize, maximumBit, &returnSize);
    int expect[] = {4,3,6,4,6,7};
    EXPECT_EQ(returnSize, numsSize);
    for(int i=0; i<returnSize; ++i)
        EXPECT_EQ(ans[i], expect[i]);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}