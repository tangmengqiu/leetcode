/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
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
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return head;
        ListNode* p=head->next;
        head->next=nullptr;
        ListNode* h= new ListNode(-1);
        h->next=head;
        while(p){
            ListNode* pre=h;
            while(pre->next&&pre->next->val<p->val) pre=pre->next;
            ListNode* tmp =p->next;
            p->next=pre->next;
            pre->next=p;
            p=tmp;
        }
        return h->next;
    }
};
// @lc code=end

