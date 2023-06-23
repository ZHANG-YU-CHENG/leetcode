#include "gtest/gtest.h"
#include "543_Diameter_of_Binary_Tree.cpp"
#include <vector>
#include <iostream>
using namespace std;

TEST(diameterOfBinaryTreeTest, test1) {
    Solution sol;
    // Create the input binary tree: [1,2,3,4,5]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Expected output: 3
    int expected = 3;

    // Calculate the diameter of the binary tree
    int result = sol.diameterOfBinaryTree(root);

    // Check if the result matches the expected output
    EXPECT_EQ(result, expected);

    // Clean up the dynamically allocated memory
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}