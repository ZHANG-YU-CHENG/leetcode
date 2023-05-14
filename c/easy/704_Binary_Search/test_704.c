#include "gtest/gtest.h"
#include <stdint.h>

extern int search(int* nums, int numsSize, int target);

TEST(searchTest, test1) {
    int nums[] = {-1,0,3,5,9,12};
    int numsSize = 6;
    int target = 9;
    int out = search(nums, numsSize, target);
    EXPECT_EQ(4, out);
}

TEST(searchTest, test2) {
    int nums[] = {-1,0,3,5,9,12};
    int numsSize = 6;
    int target = 2;
    int out = search(nums, numsSize, target);
    EXPECT_EQ(-1, out);
}

TEST(searchTest, test3) {
    int nums[] = {5};
    int numsSize = 1;
    int target = 5;
    int out = search(nums, numsSize, target);
    EXPECT_EQ(0, out);
}

TEST(searchTest, test4) {
    int nums[] = {2, 5};
    int numsSize = 2;
    int target = 5;
    int out = search(nums, numsSize, target);
    EXPECT_EQ(1, out);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}