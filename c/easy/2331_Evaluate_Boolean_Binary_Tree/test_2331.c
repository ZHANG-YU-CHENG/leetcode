#include "gtest/gtest.h"

/*for unit test*/
extern "C" {
#include "binary_tree_utils.h"
}

extern bool evaluateTree(struct TreeNode* root);

TEST(evaluateTreeTest, test1) {
    char* arr[] = {(char*)"2",(char*)"1",(char*)"3",(char*)"x",(char*)"x",(char*)"0",(char*)"1"};
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct TreeNode* root = NULL;
    root = arr2BT(arr, arrlen);
    bool ans = evaluateTree(root);

    EXPECT_TRUE(ans);
    deleteTree(&root);
}

TEST(evaluateTreeTest, test2) {
    char* arr[] = {(char*)"0"};
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct TreeNode* root = NULL;
    root = arr2BT(arr, arrlen);
    bool ans = evaluateTree(root);

    EXPECT_FALSE(ans);
    deleteTree(&root);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}