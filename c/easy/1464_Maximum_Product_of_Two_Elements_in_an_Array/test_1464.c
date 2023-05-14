#include "gtest/gtest.h"

extern int maxProduct(int* nums, int numsSize);

TEST(maxProductTest, test1) {
    int nums[] = {3,4,5,2};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int ans = maxProduct(nums, numsSize);
    EXPECT_EQ(ans, 12); 
}

TEST(maxProductTest, test2) {
    int nums[] = {1,5,4,5};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int ans = maxProduct(nums, numsSize);
    EXPECT_EQ(ans, 16); 
}

TEST(maxProductTest, test3) {
    int nums[] = {3,7};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int ans = maxProduct(nums, numsSize);
    EXPECT_EQ(ans, 12); 
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}