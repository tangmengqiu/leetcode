/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
    int maxPathSum(TreeNode* root) {
        int maxPath= INT_MIN;
        getSubTreeMaxPath(root,maxPath);
        return maxPath;
    }
    int getSubTreeMaxPath(TreeNode* root,int &maxPath){
        if(!root)return 0;
        int left = max(0,getSubTreeMaxPath(root->left,maxPath));
        int right =max(0,getSubTreeMaxPath(root->right,maxPath));
        maxPath= max(maxPath,left+right+root->val);
        return max(left+root->val,right+root->val);
    }
};
// @lc code=end

