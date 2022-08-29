#include "gtest/gtest.h"

extern int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize);

TEST(smallerNumbersThanCurrentTest, test1) {
    int nums[] = {8,1,2,2,3};
    int expect[] = {4,0,1,1,3};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int returnSize;
    int* ans = smallerNumbersThanCurrent(nums, numsSize, &returnSize);
    for(int i=0; i<returnSize; ++i)
    {
        EXPECT_EQ(ans[i], expect[i]);
    }
    if(ans) free(ans);
}

TEST(smallerNumbersThanCurrentTest, test2) {
    int nums[] = {6,5,4,8};
    int expect[] = {2,1,0,3};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int returnSize;
    int* ans = smallerNumbersThanCurrent(nums, numsSize, &returnSize);
    for(int i=0; i<returnSize; ++i)
    {
        EXPECT_EQ(ans[i], expect[i]);
    }
    if(ans) free(ans);
}

TEST(smallerNumbersThanCurrentTest, test3) {
    int nums[] = {7,7,7,7};
    int expect[] = {0,0,0,0};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int returnSize;
    int* ans = smallerNumbersThanCurrent(nums, numsSize, &returnSize);
    for(int i=0; i<returnSize; ++i)
    {
        EXPECT_EQ(ans[i], expect[i]);
    }
    if(ans) free(ans);
}

TEST(smallerNumbersThanCurrentTest, test4) {
    int nums[] = {8,1,2,2,3};
    int expect[] = {4,0,1,1,3};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int returnSize;
    int* ans = smallerNumbersThanCurrent(nums, numsSize, &returnSize);
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