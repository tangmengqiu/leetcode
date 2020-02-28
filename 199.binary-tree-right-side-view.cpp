/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if(!root) return ret;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int qs= q.size();
            queue<TreeNode*> tmp;
            while(qs--){

                TreeNode* node =q.front();
                q.pop();
                if(qs==0){
                    ret.push_back(q->val);
                }
                if(!node->left)
                    tmp.push(node->left);
                if(!node->right)
                    tmp.push(node->right);
            }
            q.tmp;
        }
        return ret;
    }
};
// @lc code=end

