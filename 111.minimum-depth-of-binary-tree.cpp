/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
    // int minDepth(TreeNode* root) {
    //     if(!root) return 0;
    //     vector<int> ret;
    //     dfs(root,ret,1);
    //     sort(ret.begin(),ret.end());
    //     return ret.front();

    // }
    // void dfs(TreeNode* root,vector<int> &ret,int depth){
    //     if(!root) return;
    //     if(!root->left&&!root->right){
    //         ret.push_back(depth);
    //         return;
    //     }
    //     if(root->left)
    //         dfs(root->left,ret,depth+1);
    //     if(root->right)
    //         dfs(root->right,ret,depth+1);
    //     return;
    // }
    // smarter one
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int l =minDepth(root->left),r =minDepth(root->right);
        return 1+(min(l,r)?min(l,r):max(l,r));

    }

};
// @lc code=end

