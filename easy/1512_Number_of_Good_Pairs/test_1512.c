#include "gtest/gtest.h"

extern int numIdenticalPairs(int* nums, int numsSize);

TEST(numIdenticalPairsTest, test1) {
    int nums[] = {1,2,3,1,1,3};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int ans = numIdenticalPairs(nums, numsSize);
    EXPECT_EQ(ans, 4);
}

TEST(numIdenticalPairsTest, test2) {
    int nums[] = {1,1,1,1};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int ans = numIdenticalPairs(nums, numsSize);
    EXPECT_EQ(ans, 6);
}

TEST(numIdenticalPairsTest, test3) {
    int nums[] = {1,2,3};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int ans = numIdenticalPairs(nums, numsSize);
    EXPECT_EQ(ans, 0);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}