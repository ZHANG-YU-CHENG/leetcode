#include "gtest/gtest.h"

extern "C" {
#include "binary_tree_utils.h"
}

extern int* inorderTraversal(struct TreeNode* root, int* returnSize);

TEST(inorderTraversalTest, test1) {
    char* arr[] = {(char*)"1",(char*)"x",(char*)"2",(char*)"3"};
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct TreeNode* root = NULL;
    root = arr2BT(arr, arrlen);
    int returnSize = 0;
    int* out = NULL;
    int ans[] = {1,3,2};
    out = inorderTraversal(root, &returnSize);
    EXPECT_EQ(returnSize, 3);
    for(int i=0; i<returnSize; ++i)
    {
        EXPECT_EQ(out[i], ans[i]);
    }
    if(root) free(root);
    if(out) free(out);
}

TEST(inorderTraversalTest, test2) {
    char* arr[] = {};
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct TreeNode* root = NULL;
    root = arr2BT(arr, arrlen);
    int returnSize = 0;
    int* out = NULL;
    int ans[] = {};
    out = inorderTraversal(root, &returnSize);
    EXPECT_EQ(returnSize, 0);
    for(int i=0; i<returnSize; ++i)
    {
        EXPECT_EQ(out[i], ans[i]);
    }
    if(root) free(root);
    if(out) free(out);
}

TEST(inorderTraversalTest, test3) {
    char* arr[] = {(char*)"1"};
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct TreeNode* root = NULL;
    root = arr2BT(arr, arrlen);
    int returnSize = 0;
    int* out = NULL;
    int ans[] = {1};
    out = inorderTraversal(root, &returnSize);
    EXPECT_EQ(returnSize, 1);
    for(int i=0; i<returnSize; ++i)
    {
        EXPECT_EQ(out[i], ans[i]);
    }
    if(root) free(root);
    if(out) free(out);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}