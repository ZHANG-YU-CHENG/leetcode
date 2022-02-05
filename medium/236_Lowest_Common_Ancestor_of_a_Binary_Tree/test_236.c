#include "gtest/gtest.h"

/*for unit test*/
extern "C" {
#include "binary_tree_utils.h"
}

extern bool findUniqueNode(struct TreeNode* root, struct TreeNode** target, int val);
extern struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q);

TEST(lowestCommonAncestorTest, test1) {
    char* arr[] = {(char*)"3",(char*)"5",(char*)"1",(char*)"6",(char*)"2",(char*)"0",(char*)"8",(char*)"x",(char*)"x",(char*)"7",(char*)"4"};
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct TreeNode* root = NULL;
    root = arr2BT(arr, arrlen);
    
    struct TreeNode* p = NULL;
    findUniqueNode(root, &p, 5);
    struct TreeNode* q = NULL;
    findUniqueNode(root, &q, 1);

    struct TreeNode* anc = NULL;
    anc = lowestCommonAncestor(root, p, q);
    int anc_val = anc->val;
    EXPECT_EQ(3, anc_val);
}

TEST(lowestCommonAncestorTest, test2) {
    char* arr[] = {(char*)"3",(char*)"5",(char*)"1",(char*)"6",(char*)"2",(char*)"0",(char*)"8",(char*)"x",(char*)"x",(char*)"7",(char*)"4"};
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct TreeNode* root = NULL;
    root = arr2BT(arr, arrlen);

    struct TreeNode* p = NULL;
    findUniqueNode(root, &p, 5);
    struct TreeNode* q = NULL;
    findUniqueNode(root, &q, 4);

    struct TreeNode* anc = NULL;
    anc = lowestCommonAncestor(root, p, q);
    int anc_val = anc->val;
    EXPECT_EQ(5, anc_val);
}

TEST(lowestCommonAncestorTest, test3) {
    char* arr[] = {(char*)"1",(char*)"2"};
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct TreeNode* root = NULL;
    root = arr2BT(arr, arrlen);

    struct TreeNode* p = NULL;
    findUniqueNode(root, &p, 1);
    struct TreeNode* q = NULL;
    findUniqueNode(root, &q, 2);

    struct TreeNode* anc = NULL;
    anc = lowestCommonAncestor(root, p, q);
    int anc_val = anc->val;
    EXPECT_EQ(1, anc_val);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}