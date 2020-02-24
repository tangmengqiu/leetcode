/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p&&!q)return true;
        else if(p&&!q)return false;
        else if(!p&&q)return false;
        else{
            if(p->val!=q->val)return false;
            return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
        }
        return true;
    }
};
// @lc code=end

