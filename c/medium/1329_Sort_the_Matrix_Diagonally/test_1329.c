#include "gtest/gtest.h"

extern int** diagonalSort(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes);

TEST(diagonalSortTest, test1) {
    int mat0[] = {3,3,1,1};
    int mat1[] = {2,2,1,2};
    int mat2[] = {1,1,1,2};
    int* mat[] = {(int*)mat0, (int*)mat1, (int*)mat2};
    int matSize = sizeof(mat)/sizeof(mat[0]);
    int matColSize[] = {4,4,4};
    int returnSize;
    int* returnColumnSizes;

    int** ans = diagonalSort(mat, matSize, matColSize, &returnSize, &returnColumnSizes);

    EXPECT_EQ(returnSize, matSize);

    for(int i=0; i<returnSize; ++i)
    {
        EXPECT_EQ(returnColumnSizes[i], matColSize[i]);
    }

    int expect0[] = {1,1,1,1};
    int expect1[] = {1,2,2,2};
    int expect2[] = {1,2,3,3};
    int* expect[] = {(int*)expect0, (int*)expect1, (int*)expect2};
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
}

TEST(diagonalSortTest, test2) {
    int mat0[] = {11,25,66,1,69,7};
    int mat1[] = {23,55,17,45,15,52};
    int mat2[] = {75,31,36,44,58,8};
    int mat3[] = {22,27,33,25,68,4};
    int mat4[] = {84,28,14,11,5,50};
    int* mat[] = {(int*)mat0, (int*)mat1, (int*)mat2, (int*)mat3, (int*)mat4};
    int matSize = sizeof(mat)/sizeof(mat[0]);
    int matColSize[] = {6,6,6,6,6};
    int returnSize;
    int* returnColumnSizes;

    int** ans = diagonalSort(mat, matSize, matColSize, &returnSize, &returnColumnSizes);

    EXPECT_EQ(returnSize, matSize);

    for(int i=0; i<returnSize; ++i)
    {
        EXPECT_EQ(returnColumnSizes[i], matColSize[i]);
    }

    int expect0[] = {5,17,4,1,52,7};
    int expect1[] = {11,11,25,45,8,69};
    int expect2[] = {14,23,25,44,58,15};
    int expect3[] = {22,27,31,36,50,66};
    int expect4[] = {84,28,75,33,55,68};
    int* expect[] = {(int*)expect0, (int*)expect1, (int*)expect2, (int*)expect3, (int*)expect4};
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
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}