/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head, *fast=head;
        while(slow&&fast){
           
            fast=fast->next;
            if(!fast){
                return nullptr;
            }
            fast=fast->next;
            slow=slow->next;
            if(fast==slow) break;
        }
        if(!fast)return fast;
        slow =head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};
// @lc code=end

