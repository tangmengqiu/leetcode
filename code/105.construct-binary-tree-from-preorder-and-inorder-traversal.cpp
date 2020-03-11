/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         TreeNode* root=buildTreeByArray(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
         return root;
    }
    TreeNode* buildTreeByArray(vector<int>& preorder, vector<int>& inorder,int l1,int r1,int l2,int r2) {
        if(l1>r1) return nullptr;
        if(l2>r2) return nullptr;
        //get left length
        int pos;
        for(int i=l2;i<=r2;i++){
            if(inorder[i]==preorder[l1]){
                pos=i;
                break;
            }
        }
        TreeNode *root= new TreeNode(preorder[l1]);
        root->left=buildTreeByArray(preorder,inorder,l1+1,l1+(pos-l2),l2,pos-1);
        root->right=buildTreeByArray(preorder,inorder,l1+(pos-l2)+1,r1,pos+1,r2);
        return root;
    }
};
// @lc code=end

