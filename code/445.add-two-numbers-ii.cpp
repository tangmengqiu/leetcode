/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> nums1,nums2;
        while(l1){
            nums1.push_back(l1->val);
            l1=l1->next;
        }
        while(l2){
            nums2.push_back(l2->val);
            l2=l2->next;
        }
        ListNode h(-1);
        int len1=nums1.size(),len2=nums2.size();
        int carry =0;
        int sum = 0;
        for(int i=len1-1,j=len2-1;i>=0||j>=0||carry>0;i--,j--){
            if(i>=0&&j>=0)sum =nums1[i]+nums2[j]+carry;
            else if(i>=0) sum =nums1[i]+carry;
            else if (j>=0) sum =nums2[j]+carry;
            else sum = carry;
            carry = sum/10;
            int left = sum%10;
            ListNode *node =new ListNode(left);
            node->next=h.next;
            h.next = node;
        }
        return h.next;
    }
};
// @lc code=end

