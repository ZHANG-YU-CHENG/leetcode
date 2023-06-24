#include "gtest/gtest.h"
#include "112_Path_Sum.cpp"
#include <vector>
#include <iostream>
using namespace std;

void deleteTree(TreeNode* root);

TEST(hasPathSumTest, test1) {
    Solution sol;
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);
    int targetSum = 22;
    EXPECT_TRUE(sol.hasPathSum(root, targetSum));
    deleteTree(root);
}

TEST(hasPathSumTest, test2) {
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    int targetSum = 5;
    EXPECT_FALSE(sol.hasPathSum(root, targetSum));
    deleteTree(root);
}

TEST(hasPathSumTest, test3) {
    Solution sol;
    TreeNode* root = nullptr;
    int targetSum = 0;
    EXPECT_FALSE(sol.hasPathSum(root, targetSum));
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