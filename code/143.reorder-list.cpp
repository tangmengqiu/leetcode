/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
    void reorderList(ListNode* head) {
        if(!head) return;
        ListNode *mid =head,*end=head, *pre=head;
        while(end){
            end=end->next;
            pre=mid
            mid=mid->next;
            if(end) end=end->next;
        }
        pre->next=nullptr;
        ListNode* h =new ListNode(-1);
        while(mid){
            ListNode* tmp =mid->next;
            mid->next=h->next;
            h->next=mid;
            mid=tmp;
        }
        ListNode* l1=head;
        ListNode* l2=h->next;
        while(l1&&l2){
            ListNode* tmp =l2->next;
            l2->next=l1->next;
            l1->next=l2;
            l2=tmp;
            l1=l1->next->next;
        }
        return;
    }
};
// @lc code=end

