#include "gtest/gtest.h"

/*for unit test*/
extern "C" {
#include "binary_tree_utils.h"
}

extern int rangeSumBST(struct TreeNode* root, int low, int high);

TEST(rangeSumBSTTest, test1) {
    char* arr[] = {(char*)"10",(char*)"5",(char*)"15",(char*)"3",(char*)"7",(char*)"x",(char*)"18"};
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct TreeNode* root = NULL;
    root = arr2BT(arr, arrlen);
    int low = 7;
    int high = 15;
    int ans = rangeSumBST(root, low, high);
    EXPECT_EQ(ans, 32);
    deleteTree(&root);
}

TEST(rangeSumBSTTest, test2) {
    char* arr[] = {(char*)"10",(char*)"5",(char*)"15",(char*)"3",(char*)"7",(char*)"13",(char*)"18",(char*)"1",(char*)"x",(char*)"6"};
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct TreeNode* root = NULL;
    root = arr2BT(arr, arrlen);
    int low = 6;
    int high = 10;
    int ans = rangeSumBST(root, low, high);
    EXPECT_EQ(ans, 23);
    deleteTree(&root);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}