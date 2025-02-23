#include "gtest/gtest.h"

extern int** flipAndInvertImage(int** image, int imageSize, int* imageColSize, int* returnSize, int** returnColumnSizes);

TEST(flipAndInvertImageTest, test1) {
    int imageCol1[] = {1,1,0};
    int imageCol2[] = {1,0,1};
    int imageCol3[] = {0,0,0};
    int* image[] = {imageCol1,imageCol2, imageCol3};
    int imageSize = sizeof(image)/sizeof(image[0]);
    int imageColSize[] = {3,3,3};
    int returnSize = 0;
    int* returnColumnSizes = NULL;
    int** returnImage = NULL;
    returnImage = flipAndInvertImage(image, imageSize, imageColSize, &returnSize, &returnColumnSizes);
    EXPECT_EQ(returnSize, imageSize);
    if(returnSize != imageSize)
    {
        for(int i=0; i<returnSize; ++i)
        {
            if(returnImage[i]) free(returnImage[i]);
        }
        if(returnImage) free(returnImage);
        if(returnColumnSizes) free(returnColumnSizes);
        return;
    }

    for(int i=0; i<returnSize; ++i)
    {
        EXPECT_EQ(returnColumnSizes[i], imageColSize[i]);
    }

    int expectedImageCol1[] = {1,0,0};
    int expectedImageCol2[] = {0,1,0};
    int expectedImageCol3[] = {1,1,1};
    int* expectedImage[] = {expectedImageCol1,expectedImageCol2, expectedImageCol3};    
    for(int i=0; i<imageSize; ++i)
    {
        for(int j=0; j<imageColSize[i]; ++j)
        {
            EXPECT_EQ(returnImage[i][j], expectedImage[i][j]);
        }
    }

    for(int i=0; i<returnSize; ++i)
    {
        if(returnImage[i]) free(returnImage[i]);
    }
    if(returnImage) free(returnImage);
    if(returnColumnSizes) free(returnColumnSizes);    
}

TEST(flipAndInvertImageTest, test2) {
    int imageCol1[] = {1,1,0,0};
    int imageCol2[] = {1,0,0,1};
    int imageCol3[] = {0,1,1,1};
    int imageCol4[] = {1,0,1,0};
    int* image[] = {imageCol1, imageCol2, imageCol3, imageCol4};
    int imageSize = sizeof(image)/sizeof(image[0]);
    int imageColSize[] = {4,4,4,4};
    int returnSize = 0;
    int* returnColumnSizes = NULL;
    int** returnImage = NULL;
    returnImage = flipAndInvertImage(image, imageSize, imageColSize, &returnSize, &returnColumnSizes);
    EXPECT_EQ(returnSize, imageSize);
    if(returnSize != imageSize)
    {
        for(int i=0; i<returnSize; ++i)
        {
            if(returnImage[i]) free(returnImage[i]);
        }
        if(returnImage) free(returnImage);
        if(returnColumnSizes) free(returnColumnSizes);
        return;
    }

    for(int i=0; i<returnSize; ++i)
    {
        EXPECT_EQ(returnColumnSizes[i], imageColSize[i]);
    }

    int expectedImageCol1[] = {1,1,0,0};
    int expectedImageCol2[] = {0,1,1,0};
    int expectedImageCol3[] = {0,0,0,1};
    int expectedImageCol4[] = {1,0,1,0};
    int* expectedImage[] = {expectedImageCol1, expectedImageCol2, expectedImageCol3, expectedImageCol4};    
    for(int i=0; i<imageSize; ++i)
    {
        for(int j=0; j<imageColSize[i]; ++j)
        {
            EXPECT_EQ(returnImage[i][j], expectedImage[i][j]);
        }
    }

    for(int i=0; i<returnSize; ++i)
    {
        if(returnImage[i]) free(returnImage[i]);
    }
    if(returnImage) free(returnImage);
    if(returnColumnSizes) free(returnColumnSizes);    
}

int main(int argc, char **argv) {
    printf("Running main() from %s\r\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}