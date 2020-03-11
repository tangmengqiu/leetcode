/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (30.80%)
 * Likes:    5423
 * Dislikes: 1394
 * Total Accepted:    917.4K
 * Total Submissions: 2.9M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example:
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 * 
 * 
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int flow = 0;
        ListNode* l3 = new ListNode(0);
        ListNode* last=l3;
        while(l1!=NULL||l2!=NULL||flow==1){
            int tmp=0;
            if(l1!=NULL){
                tmp+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                tmp+=l2->val;
                l2=l2->next;
            }
            if(flow){
                tmp+=flow;
            }
             ListNode* temp = new ListNode(0);
             temp->val=tmp%10;
             temp->next=NULL;
             last->next=temp;
             last=temp;
             flow=tmp/10;
        }
        return l3->next;
    }
};

