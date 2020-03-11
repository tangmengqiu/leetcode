/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
        if(!head||!head->next) return head;
        ListNode *newHead=new ListNode(0);
        ListNode *newTail=newHead;
        bool flag=true;
        while(head){
            while(head&&head->next&&head->val==head->next->val){
                head=head->next;
                flag=false;
            }
            if(flag){
                newTail->next=head;
                newTail=newTail->next;
            }
            head=head->next;
            flag=true;
        }
        newTail->next=nullptr;
        return newHead->next;
    }
};
// @lc code=end

