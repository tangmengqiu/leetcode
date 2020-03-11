/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root)return ret;
        queue<TreeNode*> q;
        q.push(root);
        int count=1;
        int zigzag =1;
        vector<int> level;
        while(!q.empty()){
            if(q.front()->left) q.push(q.front()->left);
            if(q.front()->right) q.push(q.front()->right);
            level.push_back(q.front()->val);
            q.pop();
            if(--count==0){
                if(zigzag%2==0) reverse(level.begin(),level.end());
                zigzag++;
                ret.push_back(level);
                level.clear();
                count = q.size();
            }
        }
        return ret;
    }
};
// @lc code=end

