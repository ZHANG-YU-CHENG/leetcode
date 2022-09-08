#include "gtest/gtest.h"

extern bool divideArray(int* nums, int numsSize);

TEST(divideArrayTest, test1) {
    int nums[] = {3,2,3,2,2,2};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    bool ans = divideArray(nums, numsSize);
    EXPECT_TRUE(ans);
}

TEST(divideArrayTest, test2) {
    int nums[] = {1,2,3,4};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    bool ans = divideArray(nums, numsSize);
    EXPECT_FALSE(ans);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}