#include "gtest/gtest.h"

extern int majorityElement(int* nums, int numsSize);

TEST(majorityElementTest, test1) {
    int nums[] = {3,2,3};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int ans;
    ans = majorityElement(nums, numsSize);
    EXPECT_EQ(ans, 3);
}

TEST(majorityElementTest, test2) {
    int nums[] = {2,2,1,1,1,2,2};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int ans;
    ans = majorityElement(nums, numsSize);
    EXPECT_EQ(ans, 2);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}