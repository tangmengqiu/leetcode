/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
    ListNode* reverseList(ListNode* head) {
        // if(!head) return head;
        // ListNode h(-1);
        // ListNode *p=head;
        // while(p){
        //     ListNode *tmp=p->next;
        //     p->next=h.next;
        //     h.next=p;
        //     p=tmp;
        // }
        // return h.next;
        // smarter version
        ListNode* h=nullptr;
        while(head){
            ListNode *next=head->next;
            head->next=h;
            h=head;
            head=next;
        }
        return h;
    }
};
// @lc code=end

