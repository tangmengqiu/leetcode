/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return checkIsSymmetric(root->left,root->right);
    }
    bool checkIsSymmetric(TreeNode* left,TreeNode* right){
        if(left==NULL&&right==NULL) return true;
        if(left==NULL||right==NULL) return false;
        if(left->val==right->val) return checkIsSymmetric(left->left,right->right)&&checkIsSymmetric(left->right,right->left);
        return false;
    }
};
// @lc code=end

