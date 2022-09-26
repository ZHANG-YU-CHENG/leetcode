#include "gtest/gtest.h"

extern int* sortArray(int* nums, int numsSize, int* returnSize);

TEST(sortArrayTest, test1) {
    int nums[] = {5,2,3,1};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int returnSize;
    int* ans = sortArray(nums, numsSize, &returnSize);
    EXPECT_EQ(returnSize, numsSize);

    int expect[] = {1,2,3,5};
    for(int i=0; i<returnSize; ++i)
        EXPECT_EQ(ans[i], expect[i]);
}

TEST(sortArrayTest, test2) {
    int nums[] = {5,1,1,2,0,0};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int returnSize;
    int* ans = sortArray(nums, numsSize, &returnSize);
    EXPECT_EQ(returnSize, numsSize);

    int expect[] = {0,0,1,1,2,5};
    for(int i=0; i<returnSize; ++i)
        EXPECT_EQ(ans[i], expect[i]);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}