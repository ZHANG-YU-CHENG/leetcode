/**
 * 
 * Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), 
 * construct the tree and return its root.
 * 
 * It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.
 * 
 * A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, 
 * and any descendant of Node.right has a value strictly greater than Node.val.
 * 
 * A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.
 * 
 * 
 * Example 1:
 * Input: preorder = [8,5,1,7,10,12]
 * Output: [8,5,10,1,7,null,12]
 * 
 * Example 2:
 * Input: preorder = [1,3]
 * Output: [1,null,3]
 * 
 * 
 * Constraints:
 * 1 <= preorder.length <= 100
 * 1 <= preorder[i] <= 1000
 * All the values of preorder are unique.
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

// class Solution {
// public:
//     TreeNode* bstFromPreorder(vector<int>& preorder) {
//         TreeNode* root = new TreeNode(preorder[0]);
//         for(int i = 1; i < preorder.size(); ++i){
//             bstInsert(root, preorder[i]);
//         }
//         return root;
//     }
// private:
//     void bstInsert(TreeNode* root, int val){
//         while(root){
//             if(val < root->val){
//                 if(root->left == nullptr){
//                     root->left = new TreeNode(val);
//                     break;
//                 }
//                 else{
//                     root = root->left;
//                     continue;
//                 }
//             }
//             else{
//                 if(root->right == nullptr){
//                     root->right = new TreeNode(val);
//                     break;
//                 }
//                 else{
//                     root = root->right;
//                     continue;
//                 }
//             }
//         }
//     }
// };

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return constructBST(preorder, 0, preorder.size()-1);
    }
private:
    TreeNode* constructBST(vector<int>& preorder, int start, int end){
        if(start > end)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[start]);
        int i = start+1;
        for(i = start+1; i <= end; ++i){
            if(preorder[i] > preorder[start])
                break;
        }
        // 8,5,1,7,10,12
        // i = 4, val = 10
        root->left = constructBST(preorder, start+1, i-1); //left tree
        root->right = constructBST(preorder, i, end); //right tree
        return root;
    }
};