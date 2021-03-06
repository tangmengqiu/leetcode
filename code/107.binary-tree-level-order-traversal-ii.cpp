/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root)return ret;
        queue<TreeNode*> q;
        q.push(root);
        int count=1;
        vector<int> level;
        while(!q.empty()){
            if(q.front()->left) q.push(q.front()->left);
            if(q.front()->right) q.push(q.front()->right);
            level.push_back(q.front()->val);
            q.pop();
            if(--count==0){
                ret.push_back(level);
                level.clear();
                count = q.size();
            }
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};
// @lc code=end

