#include "gtest/gtest.h"
#include <stdint.h>

extern int searchInsert(int* nums, int numsSize, int target);

TEST(searchInsertTest, test1) {
    int nums[] = {1,3,5,6};
    int numsSize = 4;
    int target = 5;
    int out = searchInsert(nums, numsSize, target);
    EXPECT_EQ(2, out);
}

TEST(searchInsertTest, test2) {
    int nums[] = {1,3,5,6};
    int numsSize = 4;
    int target = 2;
    int out = searchInsert(nums, numsSize, target);
    EXPECT_EQ(1, out);
}

TEST(searchInsertTest, test3) {
    int nums[] = {1,3,5,6};
    int numsSize = 4;
    int target = 7;
    int out = searchInsert(nums, numsSize, target);
    EXPECT_EQ(4, out);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}