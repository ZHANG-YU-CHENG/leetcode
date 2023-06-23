#include "gtest/gtest.h"
#include "144_Binary_Tree_Preorder_Traversal.cpp"
#include <vector>
#include <iostream>
using namespace std;

TEST(preorderTraversalTest, test1) {
    Solution sol;

    // Create the input binary tree: [1, null, 2, 3]
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    
    // Expected output: [1, 2, 3]
    vector<int> expected = {1, 2, 3};
    
    // Perform the preorder traversal
    vector<int> result = sol.preorderTraversal(root);
    
    // Check if the result matches the expected output
    EXPECT_EQ(result, expected);
    
    // Clean up the dynamically allocated memory
    delete root->right->left;
    delete root->right;
    delete root;
}

TEST(preorderTraversalTest, test2) {
    Solution sol;

    // Create an empty binary tree
    TreeNode* root = nullptr;
    
    // Expected output: []
    vector<int> expected = {};
    
    // Perform the preorder traversal
    vector<int> result = sol.preorderTraversal(root);
    
    // Check if the result matches the expected output
    EXPECT_EQ(result, expected);
}

TEST(preorderTraversalTest, test3) {
    Solution sol;

    // Create a single-node binary tree: [1]
    TreeNode* root = new TreeNode(1);
    
    // Expected output: [1]
    vector<int> expected = {1};
    
    // Perform the preorder traversal
    vector<int> result = sol.preorderTraversal(root);
    
    // Check if the result matches the expected output
    EXPECT_EQ(result, expected);
    
    // Clean up the dynamically allocated memory
    delete root;
}

TEST(preorderTraversalTest, test4) {
    Solution sol;

    // Create the input binary tree: [3, 1, 2]
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    
    // Expected output: [3, 1, 2]
    vector<int> expected = {3, 1, 2};
    
    // Perform the preorder traversal
    vector<int> result = sol.preorderTraversal(root);
    
    // Check if the result matches the expected output
    EXPECT_EQ(result, expected);
    
    // Clean up the dynamically allocated memory
    delete root->left;
    delete root->right;
    delete root;
}

TEST(preorderTraversalTest, test5) {
    Solution sol;

    // Create the input binary tree: [1,4,3,2]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(2);
    
    // Expected output: [1, 4, 2, 3]
    std::vector<int> expected = {1, 4, 2, 3};
    
    // Perform the preorder traversal
    std::vector<int> result = sol.preorderTraversal(root);
    
    // Check if the result matches the expected output
    EXPECT_EQ(result, expected);
    
    // Clean up the dynamically allocated memory
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}