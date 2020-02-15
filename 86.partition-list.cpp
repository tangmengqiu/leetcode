/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
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
    ListNode* partition(ListNode* head, int x) {
       if(!head) return head;
       ListNode *h2=new ListNode(1);
       ListNode *h1=new ListNode(1);
       ListNode *t1=h1;
       ListNode *t2 =h2;
       while(head){
           if(head->val<x){
               t1->next=head;
               t1=t1->next;
           }else{
               t2->next=head;
               t2=t2->next;
           }
           head=head->next;
       }
       t1->next=h2->next;
       t2->next=nullptr;
       return h1->next;
    }
};
// @lc code=end

