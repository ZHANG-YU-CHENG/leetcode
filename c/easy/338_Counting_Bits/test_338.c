#include "gtest/gtest.h"

extern int* countBits(int n, int* returnSize);

TEST(countBitsTest, test1) {
    int n = 2;
    int returnSize;
    int* out = countBits(n, &returnSize);
    EXPECT_EQ(3, returnSize);
    int ans[3] = {0, 1, 1};
    for(int i=0; i<returnSize; ++i)
    {
        EXPECT_EQ(ans[i], out[i]);
    }
    if(out) free(out);
    out = NULL;
}

TEST(countBitsTest, test2) {
    int n = 5;
    int returnSize;
    int* out = countBits(n, &returnSize);
    EXPECT_EQ(6, returnSize);
    int ans[6] = {0,1,1,2,1,2};
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