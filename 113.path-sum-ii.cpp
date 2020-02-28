/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        vector<int> pre;
        dfs(ret,pre,root,sum);
        return ret;

    }
    void dfs(vector<vector<int>> &ret,vector<int> pre,TreeNode* root,int need){
        if(!root) return;
        pre.push_back(root->val);
        if(root->val==need&&!root->left&&!root->right){
            ret.push_back(pre);
            return;
        }
        if(root->left) {
            dfs(ret,pre,root->left,need-(root->val));
        }
        if(root->right) {
            dfs(ret,pre,root->right,need-(root->val));
        }
        return;
    }
};
// @lc code=end

