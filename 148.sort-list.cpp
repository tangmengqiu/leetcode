/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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
    ListNode* sortList(ListNode* head) {
        if(!head) return head;
        if(!head->next) return head;
        // ListNode *p =head->next;
        ListNode *fast=head->next,*slow =head;
        while(fast&&fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* h2=slow->next;
        slow->next=nullptr;
        ListNode *left =sortList(head);
        ListNode *right =sortList(h2);
        head = merge(left,right);
        return head ;
    }
private:
    ListNode* merge(ListNode *h1,ListNode *h2){
        ListNode h(0);
        ListNode *t= &h;
        while(h1&&h2){
            if(h1->val<h2->val){
                t->next=h1;
                h1=h1->next;
            }else{
                t->next=h2;
                h2=h2->next;
            }
            t=t->next;
        }
        t->next=(h1?h1:h2);
        return h.next;
    }

};
// @lc code=end

