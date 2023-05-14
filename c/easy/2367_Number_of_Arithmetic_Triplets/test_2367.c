#include "gtest/gtest.h"

extern int arithmeticTriplets(int* nums, int numsSize, int diff);

TEST(arithmeticTripletsTest, test1) {
    int nums[] = {0,1,4,6,7,10};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int diff = 3;
    int ans = arithmeticTriplets(nums, numsSize, diff);
    EXPECT_EQ(ans, 2);
}

TEST(arithmeticTripletsTest, test2) {
    int nums[] = {4,5,6,7,8,9};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int diff = 2;
    int ans = arithmeticTriplets(nums, numsSize, diff);
    EXPECT_EQ(ans, 2);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}