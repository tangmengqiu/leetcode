/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return nullptr;
        else if(!head->next) {
            TreeNode* root = new TreeNode(head->val);
            return root;
        }
        ListNode *slow=head, *fast=head ,*pre=head;
        while(fast&&fast->next){
            pre=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        pre->next=nullptr;
        TreeNode* root = new TreeNode(slow->val);
        if(slow==head) root->left =nullptr;
        else root->left=sortedListToBST(head);
        root->right=sortedListToBST(slow->next);
        return root;
    }
};
// @lc code=end

