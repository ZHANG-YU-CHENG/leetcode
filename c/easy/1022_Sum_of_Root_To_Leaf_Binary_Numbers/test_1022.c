#include "gtest/gtest.h"

/*for unit test*/
extern "C" {
#include "binary_tree_utils.h"
}

extern int sumRootToLeaf(struct TreeNode* root);

TEST(sumRootToLeafTest, test1) {
    char* arr1[] = {(char*)"1",(char*)"0",(char*)"1",(char*)"0",(char*)"1",(char*)"0",(char*)"1"};
    int arr1len = (int) (sizeof(arr1)/sizeof(arr1[0]));
    struct TreeNode* root = NULL;
    root = arr2BT(arr1, arr1len);

    int ans = sumRootToLeaf(root);

    EXPECT_EQ(ans, 22);
    deleteTree(&root);
}

TEST(sumRootToLeafTest, test2) {
    char* arr1[] = {(char*)"0"};
    int arr1len = (int) (sizeof(arr1)/sizeof(arr1[0]));
    struct TreeNode* root = NULL;
    root = arr2BT(arr1, arr1len);

    int ans = sumRootToLeaf(root);

    EXPECT_EQ(ans, 0);
    deleteTree(&root);
}


int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}