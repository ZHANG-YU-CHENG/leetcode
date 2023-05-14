#include "gtest/gtest.h"

extern int* sortArrayByParity(int* nums, int numsSize, int* returnSize);

TEST(sortArrayByParityTest, test1) {
    int nums[] = {3,1,2,4};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int returnSize;
    int* ans = sortArrayByParity(nums, numsSize, &returnSize);
    
    int expect0[] = {4,2,3,1};
    int expect1[] = {2,4,1,3};
    int expect2[] = {4,2,1,3};
    bool expect0_flag = true;
    bool expect1_flag = true;
    bool expect2_flag = true;
    for(int i=0; i<returnSize; i++)
    {
        if(ans[i]!=expect0[i])
            expect0_flag=false;
    }
    for(int i=0; i<returnSize; i++)
    {
        if(ans[i]!=expect1[i])
            expect1_flag=false;
    }
    for(int i=0; i<returnSize; i++)
    {
        if(ans[i]!=expect2[i])
            expect2_flag=false;
    }
    EXPECT_TRUE(expect0_flag||expect1_flag||expect2_flag);
}

TEST(sortArrayByParityTest, test2) {
    int nums[] = {0};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int returnSize;
    int* ans = sortArrayByParity(nums, numsSize, &returnSize);
    
    int expect[] = {0};

    EXPECT_EQ(ans[0],expect[0]);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}