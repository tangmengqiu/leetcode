/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
    void flatten(TreeNode* root) {
        // pre order
        if(!root) return;
        TreeNode* r =root->right;
        TreeNode* l =root->left;
        if(l){
            root->right = l;
            root->left = nullptr;
            TreeNode* pre=l;
            while(pre) {
                while(pre->right) pre=pre->right;
                if(pre->left) pre=pre->left;
                else break;
            }
            pre->right = r;
            flatten(l);
        }
        flatten(r);
        return;
    }
};
// @lc code=end

