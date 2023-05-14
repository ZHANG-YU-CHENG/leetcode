#include "gtest/gtest.h"

extern int findMin(int* nums, int numsSize);

TEST(findMinTest, test1) {
    int nums[] = {1,3,5};
    int numsSize = 3;
    int out = findMin(nums, numsSize);
    EXPECT_EQ(1, out);
}

TEST(findMinTest, test2) {
    int nums[] = {2,2,2,0,1};
    int numsSize = 5;
    int out = findMin(nums, numsSize);
    EXPECT_EQ(0, out);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}