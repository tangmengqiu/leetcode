/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
    ListNode* rotateRight(ListNode* head, int k) {
     /*    if(!head)
            return head;
        int len=0;
        ListNode* p=head;
        while(p){
            p=p->next;
            len++;
        }
        k=k%len;
        p=head;
        while (len-k>1)
        {
            p=p->next;
            k++;
        }
        ListNode* l2=p->next;
        if(!l2){
            return head;
        }
        auto l3=l2->next;
        while (l3&&l3->next)
        {
            l3=l3->next;
        }
        
        p->next=nullptr;
        if(!l3)
            l2->next=head;
        else
            l3->next=head;
        head=l2;
        return head;
         */
        if(head==nullptr||head->next==nullptr||k==0)
            return head;
        auto node =head;
        int size=1;
        while (node->next)
        {
            size++;
            node=node->next;
        }
        node->next=head;
        k=k%size;
        while(--size>=k){
            node=node->next;
        }
        auto l=node->next;
        node->next=nullptr;
        return l;
    }
};
// @lc code=end

