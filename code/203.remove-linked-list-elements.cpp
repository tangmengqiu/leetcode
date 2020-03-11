/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        ListNode helper(-1);
        ListNode *tail= &helper;
        while(head){
            if(head->val!=val){
                tail->next=head;
                tail=head;
            }
            head=head->next;
        }
        tail->next=nullptr;
        return helper.next;
        //递归版
        // if(!head) return head;
        // head->next=removeElements(head->next,val);
        // return head->val==val? head->next:head;
    }
};
// @lc code=end

