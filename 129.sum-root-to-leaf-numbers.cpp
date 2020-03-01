/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
    int sumNumbers(TreeNode* root) {
        int ret=0;
        dfs(root,0,ret);
        return ret;
    }
    void dfs(TreeNode* root,int pre,int &total){
        if(!root) return;
        pre=pre*10 +root->val;
        if(!root->left&&!root->right){
           total+=pre;
           return;
        }
        if(root->left){
            dfs(root->left,pre,total);
        }
        if(root->right){
            dfs(root->right,pre,total);
        }
    }
};
// @lc code=end

