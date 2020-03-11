/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 */
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
    ListNode* swapPairs(ListNode* head) {
        if(!head)
            return head;
        ListNode *p,*q,*pre;
        p=head;
        q=p->next;
        while(q){
           if(p==head){
               p->next=q->next;
               q->next=p;
               pre=p;
               head=q;
           }else{
               pre->next=q;
               p->next=q->next;
               q->next=p;
               pre=p;
           }
            p=p->next;
            if(!p){
                break;
            }
            q=p->next;
        }
        return head;
    }
};

