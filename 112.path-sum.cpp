/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        if(root->val==sum&&root->left==nullptr&&root->right==nullptr) return true;
        bool l=false,r=false;
        if(root->left!=nullptr){
           l = hasPathSum(root->left,sum-root->val);
        }
        if(root->right!=nullptr){
            r = hasPathSum(root->right,sum-root->val);
        }
        return (l||r);
    }
};
// @lc code=end

