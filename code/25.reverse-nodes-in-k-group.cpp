/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        //先求出总长度就很灵性
        int len=length(head);
        ListNode* preHead = new ListNode(0);
        ListNode* p;
        preHead->next=head;
        p=preHead;
        for(int i=0;i<len/k;i++){
            //头插法，每次将head之后那个节点插入到preHead的后面
            for(int j=1;j<k;j++){
                ListNode* tmp=p->next;
                p->next=head->next;
                head->next=head->next->next;
                p->next->next=tmp;
            }
            p=head;
            head=head->next;
        }
        return preHead->next;
    }
    int length(ListNode* head){
        int k=0;
        while(head!=nullptr){
            head=head->next;
            k++;
        }
        return k;
    }
};
// @lc code=end

