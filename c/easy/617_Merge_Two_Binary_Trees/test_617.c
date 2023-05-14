#include "gtest/gtest.h"

/*for unit test*/
extern "C" {
#include "binary_tree_utils.h"
}

extern struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2);

TEST(mergeTreesTest, test1) {
    char* arr1[] = {(char*)"1",(char*)"3",(char*)"2",(char*)"5"};
    int arr1len = (int) (sizeof(arr1)/sizeof(arr1[0]));
    struct TreeNode* root1 = NULL;
    root1 = arr2BT(arr1, arr1len);
    char* arr2[] = {(char*)"2",(char*)"1",(char*)"3",(char*)"x",(char*)"4",(char*)"x",(char*)"7"};
    int arr2len = (int) (sizeof(arr2)/sizeof(arr2[0]));
    struct TreeNode* root2 = NULL;
    root2 = arr2BT(arr2, arr2len);
    struct TreeNode* ans = mergeTrees(root1, root2);

    char* arr3[] = {(char*)"3",(char*)"4",(char*)"5",(char*)"5",(char*)"4",(char*)"x",(char*)"7"};
    int arr3len = (int) (sizeof(arr3)/sizeof(arr3[0]));
    struct TreeNode* expect = NULL;
    expect = arr2BT(arr3, arr3len);
    EXPECT_TRUE(compareBT(ans, expect));
}

TEST(mergeTreesTest, test2) {
    char* arr1[] = {(char*)"1"};
    int arr1len = (int) (sizeof(arr1)/sizeof(arr1[0]));
    struct TreeNode* root1 = NULL;
    root1 = arr2BT(arr1, arr1len);
    char* arr2[] = {(char*)"1",(char*)"2"};
    int arr2len = (int) (sizeof(arr2)/sizeof(arr2[0]));
    struct TreeNode* root2 = NULL;
    root2 = arr2BT(arr2, arr2len);
    struct TreeNode* ans = mergeTrees(root1, root2);

    char* arr3[] = {(char*)"2",(char*)"2"};
    int arr3len = (int) (sizeof(arr3)/sizeof(arr3[0]));
    struct TreeNode* expect = NULL;
    expect = arr2BT(arr3, arr3len);
    EXPECT_TRUE(compareBT(ans, expect));
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}