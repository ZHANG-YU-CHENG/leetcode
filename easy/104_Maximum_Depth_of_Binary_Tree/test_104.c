#include "gtest/gtest.h"

/*for unit test*/
extern "C" {
#include "binary_tree_utils.h"
}

extern int maxDepth(struct TreeNode* root);


TEST(maxDepthTest, test1) {
    char* arr[] = {(char*)"3",(char*)"9",(char*)"20",(char*)"x",(char*)"x",(char*)"15",(char*)"7"}; //expected output = 3
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct TreeNode* root = NULL;
    root = arr2BT(arr, arrlen);
    int max_depth = 0;
    max_depth =  maxDepth(root);
    EXPECT_EQ(3, max_depth);
    deleteTree(&root);
}

TEST(maxDepthTest, test2) {
    char* arr[] = {(char*)"1",(char*)"x",(char*)"2"}; //expected output = 2
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct TreeNode* root = NULL;
    root = arr2BT(arr, arrlen);
    int max_depth = 0;
    max_depth =  maxDepth(root);
    EXPECT_EQ(2, max_depth);
    deleteTree(&root);
}

TEST(maxDepthTest, test3) {
    char* arr[] = {}; //expected output = 0
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct TreeNode* root = NULL;
    root = arr2BT(arr, arrlen);
    int max_depth = 0;
    max_depth =  maxDepth(root);
    EXPECT_EQ(0, max_depth);
    deleteTree(&root);
}

TEST(maxDepthTest, test4) {
    char* arr[] = {(char*)"0"}; //expected output = 1
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct TreeNode* root = NULL;
    root = arr2BT(arr, arrlen);
    int max_depth = 0;
    max_depth =  maxDepth(root);
    EXPECT_EQ(1, max_depth);
    deleteTree(&root);
}


int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}