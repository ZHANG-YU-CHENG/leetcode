#include "gtest/gtest.h"

/*for unit test*/
extern "C" {
#include "binary_tree_utils.h"
}

extern double* averageOfLevels(struct TreeNode* root, int* returnSize);

TEST(averageOfLevelsTest, test1) {
    char* arr1[] = {(char*)"3",(char*)"9",(char*)"20",(char*)"x",(char*)"x",(char*)"15",(char*)"7"};
    int arr1len = (int) (sizeof(arr1)/sizeof(arr1[0]));
    struct TreeNode* root = NULL;
    root = arr2BT(arr1, arr1len);
    int returnSize;

    double* ans = averageOfLevels(root, &returnSize);

    EXPECT_EQ(returnSize, 3);

    double expect[] = {3.00000,14.50000,11.00000};
    for(int i=0; i<returnSize; ++i)
    {
        EXPECT_EQ(ans[i], expect[i]);
    }
    deleteTree(&root);
}

TEST(averageOfLevelsTest, test2) {
    char* arr1[] = {(char*)"3",(char*)"9",(char*)"20",(char*)"15",(char*)"7"};
    int arr1len = (int) (sizeof(arr1)/sizeof(arr1[0]));
    struct TreeNode* root = NULL;
    root = arr2BT(arr1, arr1len);
    int returnSize;

    double* ans = averageOfLevels(root, &returnSize);

    EXPECT_EQ(returnSize, 3);

    double expect[] = {3.00000,14.50000,11.00000};
    for(int i=0; i<returnSize; ++i)
    {
        EXPECT_EQ(ans[i], expect[i]);
    }
    deleteTree(&root);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}