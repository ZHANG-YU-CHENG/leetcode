#include "gtest/gtest.h"

extern int** mergeSimilarItems(int** items1, int items1Size, int* items1ColSize, int** items2, int items2Size, 
    int* items2ColSize, int* returnSize, int** returnColumnSizes);

TEST(mergeSimilarItemsTest, test1) {
    int items1_0[] = {1,1};
    int items1_1[] = {4,5};
    int items1_2[] = {3,8};
    int* items1[] = {(int*)items1_0, (int*)items1_1, (int*)items1_2};
    int items1Size = sizeof(items1)/sizeof(items1[0]);
    int items1ColSize[] = {2,2,2};
    int items2_0[] = {3,1};
    int items2_1[] = {1,5};
    int* items2[] = {(int*)items2_0, (int*)items2_1};
    int items2Size = sizeof(items2)/sizeof(items2[0]);
    int items2ColSize[] = {2,2};
    int returnSize;
    int* returnColumnSizes;
    int** ans = mergeSimilarItems(items1, items1Size, items1ColSize, items2, items2Size, items2ColSize, &returnSize, &returnColumnSizes);
    
    EXPECT_EQ(returnSize, 3);
    for(int i=0; i<returnSize; ++i)
    {
        EXPECT_EQ(returnColumnSizes[i], 2);
    }
    int expect_0[] = {1,6};
    int expect_1[] = {3,9};
    int expect_2[] = {4,5};
    int* expect[] = {(int*)expect_0, (int*)expect_1, (int*)expect_2};    
    for(int i=0; i<returnSize; ++i)
    {
        for(int j=0; j<returnColumnSizes[i]; ++j)
        {
            EXPECT_EQ(ans[i][j], expect[i][j]);
        }
    }
    
    if(returnColumnSizes) free(returnColumnSizes);
    for(int i=0; i<returnSize; ++i)
    {
        if(ans[i]) free(ans[i]);
    }
    if(ans) free(ans);
}

TEST(mergeSimilarItemsTest, test2) {
    int items1_0[] = {1,1};
    int items1_1[] = {3,2};
    int items1_2[] = {2,3};
    int* items1[] = {(int*)items1_0, (int*)items1_1, (int*)items1_2};
    int items1Size = sizeof(items1)/sizeof(items1[0]);
    int items1ColSize[] = {2,2,2};
    int items2_0[] = {2,1};
    int items2_1[] = {3,2};
    int items2_2[] = {1,3};
    int* items2[] = {(int*)items2_0, (int*)items2_1, (int*)items2_2};
    int items2Size = sizeof(items2)/sizeof(items2[0]);
    int items2ColSize[] = {2,2,2};
    int returnSize;
    int* returnColumnSizes;
    int** ans = mergeSimilarItems(items1, items1Size, items1ColSize, items2, items2Size, items2ColSize, &returnSize, &returnColumnSizes);
    
    EXPECT_EQ(returnSize, 3);
    for(int i=0; i<returnSize; ++i)
    {
        EXPECT_EQ(returnColumnSizes[i], 2);
    }
    int expect_0[] = {1,4};
    int expect_1[] = {2,4};
    int expect_2[] = {3,4};
    int* expect[] = {(int*)expect_0, (int*)expect_1, (int*)expect_2};    
    for(int i=0; i<returnSize; ++i)
    {
        for(int j=0; j<returnColumnSizes[i]; ++j)
        {
            EXPECT_EQ(ans[i][j], expect[i][j]);
        }
    }
    
    if(returnColumnSizes) free(returnColumnSizes);
    for(int i=0; i<returnSize; ++i)
    {
        if(ans[i]) free(ans[i]);
    }
    if(ans) free(ans);
}

TEST(mergeSimilarItemsTest, test3) {
    int items1_0[] = {1,3};
    int items1_1[] = {2,2};
    int* items1[] = {(int*)items1_0, (int*)items1_1};
    int items1Size = sizeof(items1)/sizeof(items1[0]);
    int items1ColSize[] = {2,2};
    int items2_0[] = {7,1};
    int items2_1[] = {2,2};
    int items2_2[] = {1,4};
    int* items2[] = {(int*)items2_0, (int*)items2_1, (int*)items2_2};
    int items2Size = sizeof(items2)/sizeof(items2[0]);
    int items2ColSize[] = {2,2,2};
    int returnSize;
    int* returnColumnSizes;
    int** ans = mergeSimilarItems(items1, items1Size, items1ColSize, items2, items2Size, items2ColSize, &returnSize, &returnColumnSizes);
    
    EXPECT_EQ(returnSize, 3);
    for(int i=0; i<returnSize; ++i)
    {
        EXPECT_EQ(returnColumnSizes[i], 2);
    }
    int expect_0[] = {1,7};
    int expect_1[] = {2,4};
    int expect_2[] = {7,1};
    int* expect[] = {(int*)expect_0, (int*)expect_1, (int*)expect_2};    
    for(int i=0; i<returnSize; ++i)
    {
        for(int j=0; j<returnColumnSizes[i]; ++j)
        {
            EXPECT_EQ(ans[i][j], expect[i][j]);
        }
    }
    
    if(returnColumnSizes) free(returnColumnSizes);
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