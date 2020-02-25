/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        Node* cur;// current node in current level
        Node* pre; //pre node of next level
        Node* head; //first node of next level
        cur=root;
        while(cur){
            //handl current level
            while(cur){
                if(cur->left){
                    if(pre){
                        pre->next =cur->left;
                    }else{
                        pre=cur->left;
                        head=cur->left;
                    }
                    cur=cur->left;
                }
                if(cur->right){
                    if(pre){
                        pre->next =cur->right;
                    }else{
                        pre=cur->right;
                        head=cur->right;
                    }
                    pre=cur->right;
                }
                cur=cur->next;
            }

            //move to next level
            cur=head;
            head=nullptr;
            pre=nullptr;
        }
        return root;
    }
};
// @lc code=end

