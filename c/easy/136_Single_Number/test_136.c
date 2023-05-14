#include "gtest/gtest.h"

extern int singleNumber(int* nums, int numsSize);

TEST(singleNumberTest, test1) {
    int numsSize = 3;
    int nums[] = {2,2,1};
    int ans = 1;
    int out = singleNumber(nums, numsSize);
    EXPECT_EQ(ans, out);
}

TEST(singleNumberTest, test2) {
    int numsSize = 5;
    int nums[] = {4,1,2,1,2};
    int ans = 4;
    int out = singleNumber(nums, numsSize);
    EXPECT_EQ(ans, out);
}

TEST(singleNumberTest, test3) {
    int numsSize = 1;
    int nums[] = {1};
    int ans = 1;
    int out = singleNumber(nums, numsSize);
    EXPECT_EQ(ans, out);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}