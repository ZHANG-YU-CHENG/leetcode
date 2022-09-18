#include "gtest/gtest.h"

/*for unit test*/
extern "C" {
#include "binary_tree_utils.h"
}

extern struct TreeNode* searchBST(struct TreeNode* root, int val);

TEST(searchBSTTest, test1) {
    char* arr1[] = {(char*)"4",(char*)"2",(char*)"7",(char*)"1",(char*)"3"};
    int arr1len = (int) (sizeof(arr1)/sizeof(arr1[0]));
    struct TreeNode* root = NULL;
    root = arr2BT(arr1, arr1len);
    int val = 2;
    struct TreeNode* ans = searchBST(root, val);

    char* arr2[] = {(char*)"2",(char*)"1",(char*)"3"};
    int arr2len = (int) (sizeof(arr2)/sizeof(arr2[0]));
    struct TreeNode* expect = NULL;
    expect = arr2BT(arr2, arr2len);

    EXPECT_TRUE(compareBT(ans, expect));
    deleteTree(&root);
    deleteTree(&expect);
}

TEST(searchBSTTest, test2) {
    char* arr1[] = {(char*)"4",(char*)"2",(char*)"7",(char*)"1",(char*)"3"};
    int arr1len = (int) (sizeof(arr1)/sizeof(arr1[0]));
    struct TreeNode* root = NULL;
    root = arr2BT(arr1, arr1len);
    int val = 5;
    struct TreeNode* ans = searchBST(root, val);

    struct TreeNode* expect = NULL;

    EXPECT_TRUE(compareBT(ans, expect));
    deleteTree(&root);
    deleteTree(&expect);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}