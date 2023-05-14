#include "gtest/gtest.h"

extern int singleNumber(int* nums, int numsSize);

TEST(singleNumberTest, test1) {
    int numsSize = 4;
    int nums[] = {2,2,3,2};
    int ans = 3;
    int out = singleNumber(nums, numsSize);
    EXPECT_EQ(ans, out);
}

TEST(singleNumberTest, test2) {
    int numsSize = 7;
    int nums[] = {0,1,0,1,0,1,99};
    int ans = 99;
    int out = singleNumber(nums, numsSize);
    EXPECT_EQ(ans, out);
}

TEST(singleNumberTest, test3) {
    int numsSize = 10;
    int nums[] = {-2,-2,1,1,4,1,4,4,-4,-2};
    int ans = -4;
    int out = singleNumber(nums, numsSize);
    EXPECT_EQ(ans, out);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}