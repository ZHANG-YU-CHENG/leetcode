#include "gtest/gtest.h"
#include "1008_Construct_Binary_Search_Tree_from_Preorder_Traversal.cpp"
#include <vector>
#include <iostream>
using namespace std;

bool isSameTree(TreeNode* p, TreeNode* q);
void deleteTree(TreeNode* root);

TEST(bstFromPreorderTest, test1) {
    Solution sol;
    // Input: [8,5,1,7,10,12]
    std::vector<int> preorder = {8, 5, 1, 7, 10, 12};
    
    // Expected output: [8, 5, 10, 1, 7, null, 12]
    TreeNode* expected = new TreeNode(8);
    expected->left = new TreeNode(5);
    expected->right = new TreeNode(10);
    expected->left->left = new TreeNode(1);
    expected->left->right = new TreeNode(7);
    expected->right->right = new TreeNode(12);
    
    // Construct the binary search tree
    TreeNode* result = sol.bstFromPreorder(preorder);
    
    // Compare the constructed tree with the expected output
    EXPECT_TRUE(isSameTree(result, expected));
    
    // Clean up the dynamically allocated memory
    deleteTree(expected);
    deleteTree(result);
}

TEST(bstFromPreorderTest, test2) {
    Solution sol;
    // Input: [1,3]
    std::vector<int> preorder = {1, 3};
    
    // Expected output: [1, null, 3]
    TreeNode* expected = new TreeNode(1);
    expected->right = new TreeNode(3);
    
    // Construct the binary search tree
    TreeNode* result = sol.bstFromPreorder(preorder);
    
    // Compare the constructed tree with the expected output
    EXPECT_TRUE(isSameTree(result, expected));
    
    // Clean up the dynamically allocated memory
    deleteTree(expected);
    deleteTree(result);
}

// Helper function to check if two binary trees are identical
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr) {
        return true;
    }
    if (p == nullptr || q == nullptr) {
        return false;
    }
    return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

// Helper function to delete a binary tree
void deleteTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}