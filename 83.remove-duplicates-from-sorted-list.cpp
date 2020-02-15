/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode* p=head->next; 
        ListNode* pre=head;
        while(p){
            while(p&&pre&&p->val==pre->val){
                p=p->next;
            }
            pre->next=p;
            pre=p;
            p=p->next;
        }
        pre->next=nullptr;
        return head;
    }
};
// @lc code=end

