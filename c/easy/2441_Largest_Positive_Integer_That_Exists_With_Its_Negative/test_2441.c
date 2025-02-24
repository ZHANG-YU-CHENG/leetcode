#include "gtest/gtest.h"

extern int findMaxK(int* nums, int numsSize);

TEST(findMaxKTest, test1) {
    int nums[] = {-1,2,-3,3};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int max = 0;
    max = findMaxK(nums, numsSize);
    EXPECT_EQ(max, 3);
}

TEST(findMaxKTest, test2) {
    int nums[] = {-1,10,6,7,-7,1};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int max = 0;
    max = findMaxK(nums, numsSize);
    EXPECT_EQ(max, 7);
}

TEST(findMaxKTest, test3) {
    int nums[] = {-10,8,6,7,-2,-3};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int max = 0;
    max = findMaxK(nums, numsSize);
    EXPECT_EQ(max, -1);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\r\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}