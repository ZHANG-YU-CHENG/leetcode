/**
 * 
 * Given the root of a binary tree, return the preorder traversal of its nodes' values.
 * 
 * 
 * Example 1:
 * Input: root = [1,null,2,3]
 * Output: [1,2,3]
 * 
 * Example 2:
 * Input: root = []
 * Output: []
 * 
 * Example 3:
 * Input: root = [1]
 * Output: [1]
 * 
 * 
 * Constraints:
 * The number of nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
 * 
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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

//// recursive solution
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         preorderTraversal_helper(root);
//         return out;
//     }
//     vector<int> out = {};
//     void preorderTraversal_helper(TreeNode* root) {
//         if(root == nullptr){
//             return;
//         }
//         out.push_back(root->val);
//         preorderTraversal_helper(root->left);
//         preorderTraversal_helper(root->right);
//     }    
// };


// iterative solution
#include <stack>
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr)
            return vector<int>();

        stack<TreeNode*> s;
        vector<int> out;
        s.push(root);
        while(!s.empty()){
            TreeNode* curr = s.top();
            s.pop();
            out.push_back(curr->val);
            if(curr->right){
                s.push(curr->right);
            }
            if(curr->left){
                s.push(curr->left);
            }
        }
        return out;
    }   
};

