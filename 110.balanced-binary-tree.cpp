/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    bool isBalanced(TreeNode* root) {
       bool isBalanced =true;
       getHeight(root,isBalanced);
       return isBalanced;
        
    }
    int getHeight(TreeNode* root,bool &isBalanced ){
        if(!isBalanced) return 0;
        if(root==nullptr){
            isBalanced =true;
            return 0;
        }
        int l = getHeight(root->left,isBalanced);
        int r = getHeight(root->right,isBalanced);
        if(!isBalanced) return 0;
        if(abs(l-r)>1) isBalanced=false;
        return max(l,r)+1;
    }
};
// @lc code=end

