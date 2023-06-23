/**
 * 
 * Given the root of a binary tree, return the length of the diameter of the tree.
 * 
 * The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
 * This path may or may not pass through the root.
 * 
 * The length of a path between two nodes is represented by the number of edges between them.
 * 
 * 
 * Example 1:
 * Input: root = [1,2,3,4,5]
 * Output: 3
 * Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
 * 
 * Example 2:
 * Input: root = [1,2]
 * Output: 1
 * 
 * 
 * Constraints:
 * The number of nodes in the tree is in the range [1, 10^4].
 * -100 <= Node.val <= 100
 * 
 */

#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        diameterOfBinaryTree_helper(root);
        return diameter;
    }
    int diameter = 0;
    int diameterOfBinaryTree_helper(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int leftDepth = diameterOfBinaryTree_helper(root->left);
        int rightDepth = diameterOfBinaryTree_helper(root->right);
        int currDepth = leftDepth + rightDepth; //curr depth = left depth + right depth
        diameter = diameter > currDepth ? diameter : currDepth; //update diameter
        return leftDepth > rightDepth ? leftDepth+1 : rightDepth+1; //return child's max depth
    }
};

