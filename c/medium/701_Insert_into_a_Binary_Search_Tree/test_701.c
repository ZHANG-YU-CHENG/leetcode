#include "gtest/gtest.h"

/*for unit test*/
extern "C" {
#include "binary_tree_utils.h"
}

extern struct TreeNode* insertIntoBST(struct TreeNode* root, int val);

TEST(insertIntoBSTTest, test1) {
    char* arr[] = {(char*)"4",(char*)"2",(char*)"7",(char*)"1",(char*)"3"};
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct TreeNode* root = NULL;
    root = arr2BT(arr, arrlen);

    struct TreeNode* BST = insertIntoBST(root, 5);

    EXPECT_EQ(1, 1); //TO DO : compare BST with ans BST

    deleteTree(&root);
}

TEST(insertIntoBSTTest, test2) {
    char* arr[] = {(char*)"40",(char*)"20",(char*)"60",(char*)"30",(char*)"50",(char*)"70"};
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct TreeNode* root = NULL;
    root = arr2BT(arr, arrlen);

    struct TreeNode* BST = insertIntoBST(root, 25);

    EXPECT_EQ(1, 1); //TO DO : compare BST with ans BST

    deleteTree(&root);
}

TEST(insertIntoBSTTest, test3) {
    char* arr[] = {(char*)"4",(char*)"2",(char*)"7",(char*)"1",(char*)"3"};//,(char*)"x",(char*)"x",(char*)"x",(char*)"x",(char*)"x",(char*)"x"}; //core dump
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct TreeNode* root = NULL;
    root = arr2BT(arr, arrlen);

    struct TreeNode* BST = insertIntoBST(root, 5);

    EXPECT_EQ(1, 1); //TO DO : compare BST with ans BST

    deleteTree(&root);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}