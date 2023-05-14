#include "gtest/gtest.h"

extern int sumOfUnique(int* nums, int numsSize);

TEST(sumOfUniqueTest, test1) {
    int nums[] = {1,2,3,2};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int ans = sumOfUnique(nums, numsSize);
    EXPECT_EQ(ans, 4);
}

TEST(sumOfUniqueTest, test2) {
    int nums[] = {1,1,1,1,1};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int ans = sumOfUnique(nums, numsSize);
    EXPECT_EQ(ans, 0);
}

TEST(sumOfUniqueTest, test3) {
    int nums[] = {1,2,3,4,5};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int ans = sumOfUnique(nums, numsSize);
    EXPECT_EQ(ans, 15);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}