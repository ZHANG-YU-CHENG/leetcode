#include "gtest/gtest.h"
#include "1026_Maximum_Difference_Between_Node_and_Ancestor.cpp"
#include <vector>
#include <iostream>
#include <climits>
using namespace std;

void deleteTree(TreeNode* root);

TEST(maxAncestorDiffTest, test1) {
    Solution sol;
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->right->right = new TreeNode(14);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);
    root->right->right->left = new TreeNode(13);
    int result = sol.maxAncestorDiff(root);
    EXPECT_EQ(result, 7);
    deleteTree(root);
}

TEST(maxAncestorDiffTest, test2) {
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->left = new TreeNode(0);
    int result = sol.maxAncestorDiff(root);
    EXPECT_EQ(result, 3);
    deleteTree(root);
}

// Helper function to delete the binary tree
void deleteTree(TreeNode* root) {
    if (root == nullptr) return;
    
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}