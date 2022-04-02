#include "gtest/gtest.h"

extern int* singleNumber(int* nums, int numsSize, int* returnSize);

TEST(singleNumberTest, test1) {
    int numsSize = 6;
    int nums[] = {1,2,1,3,2,5};
    int returnSize;
    int ans[] = {3,5}; //or {5,3}
    int* out = singleNumber(nums, numsSize, &returnSize);
    EXPECT_EQ(returnSize, 2);
    for(int i=0; i<returnSize; ++i)
    {
        EXPECT_EQ(ans[i], out[i]);
    }
    if(out) free(out);
    out = NULL;
}

TEST(singleNumberTest, test2) {
    int numsSize = 2;
    int nums[] = {-1,0};
    int returnSize;
    int ans[] = {-1,0}; //or {0,-1}
    int* out = singleNumber(nums, numsSize, &returnSize);
    EXPECT_EQ(returnSize, 2);
    for(int i=0; i<returnSize; ++i)
    {
        EXPECT_EQ(ans[i], out[i]);
    }
    if(out) free(out);
    out = NULL;
}

TEST(singleNumberTest, test3) {
    int numsSize = 2;
    int nums[] = {0,1};
    int returnSize;
    int ans[] = {1,0}; //or {0,1}
    int* out = singleNumber(nums, numsSize, &returnSize);
    EXPECT_EQ(returnSize, 2);
    for(int i=0; i<returnSize; ++i)
    {
        EXPECT_EQ(ans[i], out[i]);
    }
    if(out) free(out);
    out = NULL;
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}