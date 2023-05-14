#include "gtest/gtest.h"

/*for unit test*/
extern "C" {
#include "binary_tree_utils.h"
}

extern bool maxPathSum(struct TreeNode* root);

TEST(maxPathSumTest, test1) {
    char* arr[] = {(char*)"1",(char*)"2",(char*)"3"}; //expected output = 6
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct TreeNode* root = NULL;
    root = arr2BT(arr, arrlen);
    int sum = maxPathSum(root);
    EXPECT_EQ(6, sum);
    deleteTree(&root);
}

TEST(maxPathSumTest, test2) {
    char* arr[] = {(char*)"-10",(char*)"9",(char*)"20",(char*)"x",(char*)"x",(char*)"15",(char*)"7"}; //expected output = 42
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct TreeNode* root = NULL;
    root = arr2BT(arr, arrlen);
    int sum = maxPathSum(root);
    EXPECT_EQ(42, sum);
    deleteTree(&root);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}