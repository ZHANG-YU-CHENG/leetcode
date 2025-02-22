#include "gtest/gtest.h"

extern int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize);

TEST(intersectionTest, test1) {
    int nums1[] = {1,2,2,1};
    int nums1Size = sizeof(nums1)/sizeof(nums1[0]);
    int nums2[] = {2,2};
    int nums2Size = sizeof(nums2)/sizeof(nums2[0]);
    int* returnNums = NULL;
    int returnSize = 0;
    returnNums = intersection(nums1, nums1Size, nums2, nums2Size, &returnSize);

    int expectedNums[] = {2};
    int expectedNumsSize = sizeof(expectedNums)/sizeof(expectedNums[0]);
    EXPECT_EQ(expectedNumsSize, returnSize);

    if(expectedNumsSize != returnSize)
    {
        if(returnNums) free(returnNums);
        return;
    }

    for(int i=0; i<expectedNumsSize; ++i)
    {
        EXPECT_EQ(expectedNums[i], returnNums[i]);
    }

    if(returnNums) free(returnNums);
}

TEST(intersectionTest, test2) {
    int nums1[] = {4,9,5};
    int nums1Size = sizeof(nums1)/sizeof(nums1[0]);
    int nums2[] = {9,4,9,8,4};
    int nums2Size = sizeof(nums2)/sizeof(nums2[0]);
    int* returnNums = NULL;
    int returnSize = 0;
    returnNums = intersection(nums1, nums1Size, nums2, nums2Size, &returnSize);

    int expectedNums[] = {4,9};
    int expectedNumsSize = sizeof(expectedNums)/sizeof(expectedNums[0]);
    EXPECT_EQ(expectedNumsSize, returnSize);

    if(expectedNumsSize != returnSize)
    {
        if(returnNums) free(returnNums);
        return;
    }

    for(int i=0; i<expectedNumsSize; ++i)
    {
        EXPECT_EQ(expectedNums[i], returnNums[i]);
    }

    if(returnNums) free(returnNums);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\r\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}