/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ret;
        if(n==0) return ret;
        ret =generateBST(1,n);
        return ret;
    }
    vector<TreeNode*> generateBST(int left,int right){
        vector<TreeNode*> ret;
        if(left>right) {
           ret.push_back(nullptr) ;
           return ret;
        }
        for(int i=left;i<=right;i++){
            vector<TreeNode* > leftNodes =generateBST(left,i-1);
            vector<TreeNode* > rightNodes =generateBST(i+1,right);
            for(int j=0;j<leftNodes.size();j++){
                for(int k=0;k<rightNodes.size();k++){
                    TreeNode* root = new TreeNode(i);
                    root->left = leftNodes[j];
                    root->right=rightNodes[k];
                    ret.push_back(root);
                }
            }
        }
        return ret;
        
    }
};
// @lc code=end

