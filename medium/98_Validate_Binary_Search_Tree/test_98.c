#include "gtest/gtest.h"

/*for unit test*/
extern "C" {
#include "binary_tree_utils.h"
}

extern bool isValidBST(struct TreeNode* root);

TEST(isValidBSTTest, test1) {
    char* arr[] = {(char*)"2",(char*)"1",(char*)"3"};
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct TreeNode* root = NULL;
    root = arr2BT(arr, arrlen);

    bool isBST = isValidBST(root);

    EXPECT_EQ(true, isBST);

    deleteTree(&root);
}

TEST(isValidBSTTest, test2) {
    char* arr[] = {(char*)"5",(char*)"1",(char*)"4",(char*)"x",(char*)"x",(char*)"3",(char*)"6"};
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct TreeNode* root = NULL;
    root = arr2BT(arr, arrlen);

    bool isBST = isValidBST(root);

    EXPECT_EQ(false, isBST);

    deleteTree(&root);
}

TEST(isValidBSTTest, test3) {
    char* arr[] = {(char*)"2147483647"};
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct TreeNode* root = NULL;
    root = arr2BT(arr, arrlen);

    bool isBST = isValidBST(root);

    EXPECT_EQ(true, isBST);

    deleteTree(&root);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}