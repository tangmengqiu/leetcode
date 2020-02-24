/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    bool isValidBST(TreeNode* root) {
        vector<TreeNode*> stk;
        TreeNode *pre =nullptr;
        while(root||!stk.empty()){
            while(root){
                stk.push_back(root);
                root=root->left;
            }
            root=stk.back();
            std.pop_back();
            //如果是求BST的第K大的数，就在这里计数，第k个时返回
            if(pre&&pre->val>=root->val) return false;
            pre=root;
            root=root->right;
        }
        return true;
    }
      
};
// @lc code=end

