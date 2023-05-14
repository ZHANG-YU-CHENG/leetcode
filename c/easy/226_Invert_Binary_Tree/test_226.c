#include "gtest/gtest.h"

/*for unit test*/
extern "C" {
#include "binary_tree_utils.h"
}

extern struct TreeNode* invertTree(struct TreeNode* root);

TEST(invertTreeTest, test1) {
    char* arr1[] = {(char*)"4",(char*)"2",(char*)"7",(char*)"1",(char*)"3",(char*)"6",(char*)"9"};
    int arr1len = (int) (sizeof(arr1)/sizeof(arr1[0]));
    struct TreeNode* root = NULL;
    root = arr2BT(arr1, arr1len);

    struct TreeNode* ans = invertTree(root);

    char* arr2[] = {(char*)"4",(char*)"7",(char*)"2",(char*)"9",(char*)"6",(char*)"3",(char*)"1"};
    int arr2len = (int) (sizeof(arr2)/sizeof(arr2[0]));
    struct TreeNode* expect = NULL;
    expect = arr2BT(arr2, arr2len);

    EXPECT_TRUE(compareBT(ans, expect));
    deleteTree(&root);
    deleteTree(&expect);
}

TEST(invertTreeTest, test2) {
    char* arr1[] = {(char*)"2",(char*)"1",(char*)"3"};
    int arr1len = (int) (sizeof(arr1)/sizeof(arr1[0]));
    struct TreeNode* root = NULL;
    root = arr2BT(arr1, arr1len);
    
    struct TreeNode* ans = invertTree(root);

    char* arr2[] = {(char*)"2",(char*)"3",(char*)"1"};
    int arr2len = (int) (sizeof(arr2)/sizeof(arr2[0]));
    struct TreeNode* expect = NULL;
    expect = arr2BT(arr2, arr2len);

    EXPECT_TRUE(compareBT(ans, expect));
    deleteTree(&root);
    deleteTree(&expect);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}