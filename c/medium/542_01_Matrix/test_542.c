#include "gtest/gtest.h"

extern int** updateMatrix(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes);

TEST(updateMatrixTest, test1) {
    int matSize = 3;
    int matColSize[3] = {3, 3, 3};
    int mat0[3] = {0,0,0};
    int mat1[3] = {0,1,0};
    int mat2[3] = {0,0,0};
    int* mat[3];
    mat[0] = mat0;
    mat[1] = mat1;
    mat[2] = mat2;
    int returnSize;
    int* returnColumnSizes;
    int** returnMat;
    returnMat = updateMatrix(mat, matSize, matColSize, &returnSize, &returnColumnSizes);

    EXPECT_EQ(returnSize, 3);
    for(int i=0; i<3; ++i)
    {
        EXPECT_EQ(returnColumnSizes[i], 3);
    }
    int ans0[3] = {0,0,0};
    int ans1[3] = {0,1,0};
    int ans2[3] = {0,0,0};
    int* ans[3];
    ans[0] = ans0;
    ans[1] = ans1;
    ans[2] = ans2;
    for(int i=0; i<3; ++i)
    {
        for(int j=0; j<3; ++j)
        {
            // printf("i=%d, j=%d\n", i, j);
            EXPECT_EQ(returnMat[i][j], ans[i][j]);
        }
    }

    for(int i=0; i<3; ++i)
    {
        free(returnMat[i]);
    }
    free(returnMat);    
}

TEST(updateMatrixTest, test2) {
    int matSize = 3;
    int matColSize[3] = {3, 3, 3};
    int mat0[3] = {0,0,0};
    int mat1[3] = {0,1,0};
    int mat2[3] = {1,1,1};
    int* mat[3];
    mat[0] = mat0;
    mat[1] = mat1;
    mat[2] = mat2;
    int returnSize;
    int* returnColumnSizes;
    int** returnMat;
    returnMat = updateMatrix(mat, matSize, matColSize, &returnSize, &returnColumnSizes);

    EXPECT_EQ(returnSize, 3);
    for(int i=0; i<3; ++i)
    {
        EXPECT_EQ(returnColumnSizes[i], 3);
    }
    int ans0[3] = {0,0,0};
    int ans1[3] = {0,1,0};
    int ans2[3] = {1,2,1};
    int* ans[3];
    ans[0] = ans0;
    ans[1] = ans1;
    ans[2] = ans2;
    for(int i=0; i<3; ++i)
    {
        for(int j=0; j<3; ++j)
        {
            // printf("i=%d, j=%d\n", i, j);
            EXPECT_EQ(returnMat[i][j], ans[i][j]);
        }
    }

    for(int i=0; i<3; ++i)
    {
        free(returnMat[i]);
    }
    free(returnMat);   
}

TEST(updateMatrixTest, test3) {
    int matSize = 5;
    int matColSize[5] = {3, 3, 3, 3, 3};
    int mat0[3] = {0,1,0};
    int mat1[3] = {0,1,0};
    int mat2[3] = {0,1,0};
    int mat3[3] = {0,1,0};
    int mat4[3] = {0,1,0};
    int* mat[5];
    mat[0] = mat0;
    mat[1] = mat1;
    mat[2] = mat2;
    mat[3] = mat3;
    mat[4] = mat4;
    int returnSize;
    int* returnColumnSizes;
    int** returnMat;
    returnMat = updateMatrix(mat, matSize, matColSize, &returnSize, &returnColumnSizes);

    EXPECT_EQ(returnSize, 5);
    for(int i=0; i<5; ++i)
    {
        EXPECT_EQ(returnColumnSizes[i], 3);
    }
    int ans0[3] = {0,1,0};
    int ans1[3] = {0,1,0};
    int ans2[3] = {0,1,0};
    int ans3[3] = {0,1,0};
    int ans4[3] = {0,1,0};
    int* ans[5];
    ans[0] = ans0;
    ans[1] = ans1;
    ans[2] = ans2;
    ans[3] = ans3;
    ans[4] = ans4;
    for(int i=0; i<5; ++i)
    {
        for(int j=0; j<3; ++j)
        {
            // printf("i=%d, j=%d\n", i, j);
            EXPECT_EQ(returnMat[i][j], ans[i][j]);
        }
    }

    for(int i=0; i<5; ++i)
    {
        free(returnMat[i]);
    }
    free(returnMat);   
}

TEST(updateMatrixTest, test4) {
    int matSize = 5;
    int matColSize[5] = {5, 5, 5, 5, 5};
    int mat0[5] = {0,1,0,1,1};
    int mat1[5] = {1,1,0,0,1};
    int mat2[5] = {0,0,0,1,0};
    int mat3[5] = {1,0,1,1,1};
    int mat4[5] = {1,0,0,0,1};
    int* mat[5];
    mat[0] = mat0;
    mat[1] = mat1;
    mat[2] = mat2;
    mat[3] = mat3;
    mat[4] = mat4;
    int returnSize;
    int* returnColumnSizes;
    int** returnMat;
    returnMat = updateMatrix(mat, matSize, matColSize, &returnSize, &returnColumnSizes);

    EXPECT_EQ(returnSize, 5);
    for(int i=0; i<5; ++i)
    {
        EXPECT_EQ(returnColumnSizes[i], 5);
    }
    int ans0[5] = {0,1,0,1,2};
    int ans1[5] = {1,1,0,0,1};
    int ans2[5] = {0,0,0,1,0};
    int ans3[5] = {1,0,1,1,1};
    int ans4[5] = {1,0,0,0,1};
    int* ans[5];
    ans[0] = ans0;
    ans[1] = ans1;
    ans[2] = ans2;
    ans[3] = ans3;
    ans[4] = ans4;
    for(int i=0; i<5; ++i)
    {
        for(int j=0; j<5; ++j)
        {
            // printf("i=%d, j=%d\n", i, j);
            EXPECT_EQ(returnMat[i][j], ans[i][j]);
        }
    }

    for(int i=0; i<5; ++i)
    {
        free(returnMat[i]);
    }
    free(returnMat);   
}

//test 5
/*
Input
[[1,0,1,0,0,0,1,1,1,1],[1,1,1,0,1,1,1,1,0,1],[1,0,1,1,1,1,0,1,0,0],[1,0,1,1,1,0,1,1,1,1],[1,1,0,1,1,1,1,0,0,0],[1,1,0,0,1,0,1,1,0,1],[1,1,1,1,1,1,1,1,1,1],[1,1,0,0,0,1,1,1,0,0],[0,1,1,1,0,0,1,0,1,1],[1,1,0,0,0,1,0,1,1,0]]
Expected
[[1,0,1,0,0,0,1,2,1,2],[2,1,1,0,1,1,1,1,0,1],[1,0,1,1,2,1,0,1,0,0],[1,0,1,2,1,0,1,1,1,1],[2,1,0,1,2,1,1,0,0,0],[2,1,0,0,1,0,1,1,0,1],[2,2,1,1,1,1,2,2,1,1],[1,1,0,0,0,1,2,1,0,0],[0,1,1,1,0,0,1,0,1,1],[1,1,0,0,0,1,0,1,1,0]]
*/

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}