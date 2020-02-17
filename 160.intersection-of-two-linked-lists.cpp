/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1= getLinkListLength(headA);
        int l2 =getLinkListLength(headB);
        ListNode *longerLinkList = (l1>l2?headA:headB);
        for(int i=0;i< abs(l1-l2);i++){
            longerLinkList =longerLinkList->next;
        }
        if(l1>l2) headA=longerLinkList;
        else headB =longerLinkList;
        while(headA&&headB&&headB!=headA){
            headB=headB->next;
            headA =headA->next;
        }
        return headA;
    }
private:
    int getLinkListLength(ListNode *head){
        int l=0;
        while(head){
            l++;
            head=head->next;
        }
        return l;
    }
};
// @lc code=end

