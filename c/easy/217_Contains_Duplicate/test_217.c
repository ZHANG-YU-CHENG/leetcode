#include "gtest/gtest.h"

extern bool containsDuplicate(int* nums, int numsSize);

TEST(containsDuplicateTest, test1) {
    int nums[] = {1,2,3,1};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    bool ans;
    ans = containsDuplicate(nums, numsSize);
    EXPECT_TRUE(ans);
}

TEST(containsDuplicateTest, test2) {
    int nums[] = {1,2,3,4};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    bool ans;
    ans = containsDuplicate(nums, numsSize);
    EXPECT_FALSE(ans);
}

TEST(containsDuplicateTest, test3) {
    int nums[] = {1,1,1,3,3,4,3,2,4,2};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    bool ans;
    ans = containsDuplicate(nums, numsSize);
    EXPECT_TRUE(ans);
}



int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}