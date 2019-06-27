/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (47.39%)
 * Likes:    2251
 * Dislikes: 319
 * Total Accepted:    589.8K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
       if(!l1||(l2&&l1->val>l2->val))
            swap(l1,l2);
       if(l1)
            l1->next=mergeTwoLists(l1->next,l2);
        return l1;
    }
};

/*
    line1:makes l1 always point to the smaller node
    if not,swap thier head node
    line2:makes the remains nodes linked after l1
    the proccess like this:
    init:
        a
        |
        1 -> 2 -> 4
        b
        |
        1 -> 3 -> 4
    first:
        
        a0(1)->| a(2)->(4)     |
               | b(1)->(3)->(4)|
    swap:
         a0(1)->| b(2)->(4)     |
                | a(1)->(3)->(4)|
    return a0->next=a1:
         a0(1)->a1(1)| b(2)->(4)|
                     | a(3)->(4)|
    swap:
         a0(1)->a1(1)| a(2)->(4)|
                     | b(3)->(4)|
    return a1->next=a2:
         a0(1)->a1(1)->a2(2)| a(4)     |
                            | b(3)->(4)|
    swap :
         a0(1)->a1(1)->a2(2)| b(4)     |
                            | a(3)->(4)|
     return a2->next=a3:
        a0(1)->a1(1)->a2(2)-a3(3)| b(4)|
                                 | a(4)|
     return a3->next=a4:
         a0(1)->a1(1)->a2(2)-a3(3)->a4(4)| b(4)|
                                         | a(null)|
     swap:
         a0(1)->a1(1)->a2(2)-a3(3)->a4(4)| a(4)|
                                         | b(null)|
     return a4->next=a5:
         a0(1)->a1(1)->a2(2)-a3(3)->a4(4)->a5(4)->| a(null)|
                                                  | b(null)|
     done:
        return a=1->1->2->3->4->4
        
 */

