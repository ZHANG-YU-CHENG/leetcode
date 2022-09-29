#include "gtest/gtest.h"

extern int* sortByBits(int* arr, int arrSize, int* returnSize);

TEST(sortByBitsTest, test1) {
    int arr[] = {0,1,2,3,4,5,6,7,8};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    int returnSize;
    int* ans = sortByBits(arr, arrSize, &returnSize);
    int expect[] = {0,1,2,4,8,3,5,6,7};
    EXPECT_EQ(returnSize, arrSize);
    for(int i=0; i<returnSize; ++i)
        EXPECT_EQ(ans[i], expect[i]);
}

TEST(sortByBitsTest, test2) {
    int arr[] = {1024,512,256,128,64,32,16,8,4,2,1};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    int returnSize;
    int* ans = sortByBits(arr, arrSize, &returnSize);
    int expect[] = {1,2,4,8,16,32,64,128,256,512,1024};
    EXPECT_EQ(returnSize, arrSize);
    for(int i=0; i<returnSize; ++i)
        EXPECT_EQ(ans[i], expect[i]);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}