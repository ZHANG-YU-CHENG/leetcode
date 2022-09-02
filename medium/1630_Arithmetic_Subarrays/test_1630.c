#include "gtest/gtest.h"

extern bool* checkArithmeticSubarrays(int* nums, int numsSize, int* l, int lSize, int* r, int rSize, int* returnSize);

TEST(checkArithmeticSubarraysTest, test1) {
    int nums[] = {4,6,5,9,3,7};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int l[] = {0,0,2};
    int lSize = sizeof(l)/sizeof(l[0]);    
    int r[] = {2,3,5};
    int rSize = sizeof(r)/sizeof(r[0]); 
    int returnSize;
    bool* ans = checkArithmeticSubarrays(nums, numsSize, l, lSize, r, rSize, &returnSize);

    bool expect[] = {true,false,true};
    for(int i=0; i<returnSize; ++i)
    {
        if(expect[i]) EXPECT_TRUE(ans[i]);
        else EXPECT_FALSE(ans[i]);
    }
    if(ans) free(ans);
}

TEST(checkArithmeticSubarraysTest, test2) {
    int nums[] = {-12,-9,-3,-12,-6,15,20,-25,-20,-15,-10};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int l[] = {0,1,6,4,8,7};
    int lSize = sizeof(l)/sizeof(l[0]);    
    int r[] = {4,4,9,7,9,10};
    int rSize = sizeof(r)/sizeof(r[0]); 
    int returnSize;
    bool* ans = checkArithmeticSubarrays(nums, numsSize, l, lSize, r, rSize, &returnSize);

    bool expect[] = {false,true,false,false,true,true};
    for(int i=0; i<returnSize; ++i)
    {
        if(expect[i]) EXPECT_TRUE(ans[i]);
        else EXPECT_FALSE(ans[i]);
    }
    if(ans) free(ans);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}