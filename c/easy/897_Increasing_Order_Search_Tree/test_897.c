#include "gtest/gtest.h"

/*for unit test*/
extern "C" {
#include "binary_tree_utils.h"
}

extern struct TreeNode* increasingBST(struct TreeNode* root);

TEST(increasingBSTTest, test1) {
    char* arr1[] = {(char*)"5",(char*)"3",(char*)"6",(char*)"2",(char*)"4",(char*)"x",(char*)"8",
        (char*)"1",(char*)"x",(char*)"x",(char*)"x",(char*)"7",(char*)"9"};
    int arr1len = (int) (sizeof(arr1)/sizeof(arr1[0]));
    struct TreeNode* root = NULL;
    root = arr2BT(arr1, arr1len);
    struct TreeNode* ans = increasingBST(root);

    char* arr2[] = {(char*)"1",(char*)"x",(char*)"2",(char*)"x",(char*)"3",(char*)"x",(char*)"4",
        (char*)"x",(char*)"5",(char*)"x",(char*)"6",(char*)"x",(char*)"7",(char*)"x",(char*)"8",(char*)"x",(char*)"9"};
    int arr2len = (int) (sizeof(arr2)/sizeof(arr2[0]));
    struct TreeNode* expect = NULL;
    expect = arr2BT(arr2, arr2len);

    EXPECT_TRUE(compareBT(ans, expect));
    deleteTree(&root);
    deleteTree(&expect);
}

TEST(increasingBSTTest, test2) {
    char* arr1[] = {(char*)"5",(char*)"1",(char*)"7"};
    int arr1len = (int) (sizeof(arr1)/sizeof(arr1[0]));
    struct TreeNode* root = NULL;
    root = arr2BT(arr1, arr1len);
    struct TreeNode* ans = increasingBST(root);

    char* arr2[] = {(char*)"1",(char*)"x",(char*)"5",(char*)"x",(char*)"7"};
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