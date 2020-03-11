/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(!root) return ret;
        TreeNode *pre =nullptr;
        TreeNode *cur=root;
        TreeNode *lastRight;
        while(cur){
            if(cur->left){
                //find most right node
                pre=cur->left;
                while(pre->right&&pre->right!=cur) pre=pre->right;
                if(pre->right==nullptr){
                    pre->right= cur;
                    cur=cur->left;
                }else{
                    pre->right=nullptr;
                    getNodes(ret,cur->left,pre);
                    lastRight=cur;
                    cur=cur->right;
                }
            }else{
                lastRight=cur;
                cur=cur->right;
            }
        }
        getNodes(ret,root,lastRight);
        return ret;
    }
    void getNodes(vector<int> &ret ,TreeNode *from ,TreeNode *to){
        auto tmp=reversePath(from,to);
        while(tmp){
            ret.push_back(tmp->val);
            tmp=tmp->right;
        }
        reversePath(to,from);
    }
    TreeNode* reversePath(TreeNode *from,TreeNode *to){
        if(from==to) return from;
        TreeNode *next =from->right;
        from->right=nullptr;
        TreeNode *pre =from;
        while(next){
            auto nt=next->right;
            next->right=pre;
            pre=next;
            next=nt;
        }
        return to;
    }
};
// @lc code=end

