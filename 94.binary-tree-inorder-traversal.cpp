/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        //inorderTraveler(root,ret);
        StackTraveler(root,ret);
        return ret;
    }
    void inorderTraveler(TreeNode* root,vector<int>& ret){
        if(root==NULL) return;
        inorderTraveler(root->left,ret);
        ret.push_back(root->val);
        inorderTraveler(root->right,ret);
        return;
    }
    void StackTraveler(TreeNode* root,vector<int>& ret){
        stack<TreeNode* > st;
        while(root||!st.empty()){
            while(root){
                st.push(root);
                root=root->left;
            }
            root=st.top();
            st.pop();
            ret.push_back(root->val);
            root=root->right;
        }
    }
};
// @lc code=end

