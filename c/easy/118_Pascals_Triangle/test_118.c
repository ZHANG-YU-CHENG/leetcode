#include "gtest/gtest.h"

extern int** generate(int numRows, int* returnSize, int** returnColumnSizes);

TEST(generateTest, test1) {
    int numRows = 5;
    int returnSize;
    int* returnColumnSizes;
    int** ans = generate(numRows, &returnSize, &returnColumnSizes);

    int expect_0[] = {1};
    int expect_1[] = {1,1};
    int expect_2[] = {1,2,1};
    int expect_3[] = {1,3,3,1};
    int expect_4[] = {1,4,6,4,1};
    int* expect[5] = {(int*)expect_0,(int*)expect_1,(int*)expect_2,(int*)expect_3,(int*)expect_4};
    for(int i=0; i<returnSize; ++i)
    {
        for(int j=0; j<returnColumnSizes[i]; ++j)
        {
            EXPECT_EQ(ans[i][j], expect[i][j]);
        }
    }

    for(int i=0; i<returnSize; ++i)
    {
        if(ans[i]) free(ans[i]);
    }
    if(ans) free(ans);

    if(returnColumnSizes) free(returnColumnSizes);
}

TEST(generateTest, test2) {
    int numRows = 1;
    int returnSize;
    int* returnColumnSizes;
    int** ans = generate(numRows, &returnSize, &returnColumnSizes);

    int expect_0[] = {1};
    int* expect[1] = {(int*)expect_0};
    for(int i=0; i<returnSize; ++i)
    {
        for(int j=0; j<returnColumnSizes[i]; ++j)
        {
            EXPECT_EQ(ans[i][j], expect[i][j]);
        }
    }

    for(int i=0; i<returnSize; ++i)
    {
        if(ans[i]) free(ans[i]);
    }
    if(ans) free(ans);

    if(returnColumnSizes) free(returnColumnSizes);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}