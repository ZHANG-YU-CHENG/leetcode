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

    /* TO DO : compare two binary trees */
    struct TreeNode* ans = mergeTrees(root1, root2);
    if(ans) puts("ok");
    int tmp=1;
    EXPECT_EQ(tmp, 1);
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

    /* TO DO : compare two binary trees */
    struct TreeNode* ans = mergeTrees(root1, root2);
    if(ans) puts("ok");
    int tmp=1;
    EXPECT_EQ(tmp, 1);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}