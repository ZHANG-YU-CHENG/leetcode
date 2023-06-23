/**
 * 
 * Given the root of a binary tree, find the maximum value v for 
 * which there exist different nodes a and b where v = |a.val - b.val| and a is an ancestor of b.
 * 
 * A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.
 * 
 * 
 * Example 1:
 * Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
 * Output: 7
 * Explanation: We have various ancestor-node differences, some of which are given below :
 * |8 - 3| = 5
 * |3 - 7| = 4
 * |8 - 1| = 7
 * |10 - 13| = 3
 * Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.
 * 
 * Example 2:
 * Input: root = [1,null,2,null,0,3]
 * Output: 3
 * 
 * 
 * Constraints:
 * The number of nodes in the tree is in the range [2, 5000].
 * 0 <= Node.val <= 10^5
 * 
 */

#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// class Solution {
// public:
//     int maxDiffVal = 0;
//     int maxAncestorDiff(TreeNode* root) {
//         traversal(root);
//         return maxDiffVal;
//     }
// private:
//     void traversal(TreeNode* root){
//         if(root == nullptr)
//             return;
//         maxDiff(root, root->val);
//         traversal(root->left);
//         traversal(root->right);
//     }

//     void maxDiff(TreeNode* root, int root_val){
//         if(root == nullptr){
//             return;
//         }
//         int diff = abs(root_val - root->val);
//         maxDiffVal = maxDiffVal > diff ? maxDiffVal : diff;
//         maxDiff(root->left, root_val);
//         maxDiff(root->right, root_val);
//     }
// };

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        return maxDiff(root, root->val, root->val);
    }
private:
    int maxDiff(TreeNode* root, int curr_min, int curr_max){
        if(root == nullptr){
            return curr_max - curr_min;
        }
        curr_max = max(curr_max, root->val);
        curr_min = min(curr_min, root->val);

        int leftMaxDiff = maxDiff(root->left, curr_min, curr_max);
        int rightMaxDiff = maxDiff(root->right, curr_min, curr_max);
        
        return max(leftMaxDiff, rightMaxDiff);
    }
};