/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTreeByArray(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }
    TreeNode* buildTreeByArray(vector<int>& inorder, vector<int>& postorder,int l1,int r1,int l2,int r2) {
        if(l1>r1) return nullptr;
        if(l2>r2) return nullptr;
        //get left length
        int pos;
        for(int i=l1;i<=r1;i++){
            if(inorder[i]==postorder[r2]){
                pos=i;
                break;
            }
        }
        TreeNode *root= new TreeNode(postorder[r2]);
        root->left=buildTreeByArray(inorder,postorder,l1,pos-1,l2,l2+(pos-l1)-1);
        root->right=buildTreeByArray(inorder,postorder,pos+1,r1,l2+(pos-l1),r2-1);
        return root;
    }
};
// @lc code=end

