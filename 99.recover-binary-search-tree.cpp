/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
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
    TreeNode* first=NULL;
    TreeNode* second=NULL;
    TreeNode* prev = new TreeNode(INT_MIN);
public:
    void recoverTree(TreeNode* root) {
        //在中序遍历中找到两个不在正确递增位置上的数
        //憨憨解法
        vector<TreeNode*> s;
        TreeNode *preMaxNode =nullptr;
        int preMax=INT_MIN;
        auto r= root;
        vector<int> nodes;
        while(root||!s.empty()){
            while(root){
                s.push_back(root);
                root=root->left;
            }
            root=s.back();
            s.pop_back();
            nodes.push_back(root->val);
            root=root->right;
        }
        root =r;
        sort(nodes.begin(),nodes.end());
        int k=0
        while(root||!s.empty()){
            while(root){
                s.push_back(root);
                root=root->left;
            }
            root=s.back();
            s.pop_back();
            int v= nodes[k++];
            if(root->val!=v){
                root->val=v;
            }
            root=root->right;
        }
        //聪明解法：
        helper(root);
        swap(first->val,second->val);

    }
    void helper(TreeNode* root){
        if(!root) return;
        helper(root->left);
        if(first==NULL&&root->val<=pre->val)first = prev;
        if(first!=NULL&&root->val<=pre->val)second =root;
        pre=root;
        helper(root);
    }
};
// @lc code=end

