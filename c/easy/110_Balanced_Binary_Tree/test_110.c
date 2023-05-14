#include "gtest/gtest.h"

/*for unit test*/
extern "C" {
#include "binary_tree_utils.h"
}

extern bool isBalanced(struct TreeNode* root);

TEST(isBalancedTest, test1) {
    char* arr[] = {(char*)"3",(char*)"9",(char*)"20",(char*)"x",(char*)"x",(char*)"15",(char*)"7"}; //expected output = true
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct TreeNode* root = NULL;
    root = arr2BT(arr, arrlen);
    EXPECT_TRUE(isBalanced(root));
    deleteTree(&root);
}

TEST(isBalancedTest, test2) {
    char* arr[] = {(char*)"1",(char*)"2",(char*)"2",(char*)"3",(char*)"3",(char*)"x",(char*)"x",(char*)"4",(char*)"4"}; //expected output = false
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct TreeNode* root = NULL;
    root = arr2BT(arr, arrlen);
    EXPECT_FALSE(isBalanced(root));
    deleteTree(&root);
}

TEST(isBalancedTest, test3) {
    char* arr[] = {}; //expected output = true
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct TreeNode* root = NULL;
    root = arr2BT(arr, arrlen);
    EXPECT_TRUE(isBalanced(root));
    deleteTree(&root);
}

TEST(isBalancedTest, test4) {
    char* arr[] = {(char*)"1",(char*)"2",(char*)"2",(char*)"3",(char*)"x",(char*)"x",(char*)"3",(char*)"4",(char*)"x",(char*)"x",(char*)"4"}; //expected output = false
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct TreeNode* root = NULL;
    root = arr2BT(arr, arrlen);
    EXPECT_FALSE(isBalanced(root));
    deleteTree(&root);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}