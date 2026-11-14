/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int sz =0;
        ListNode*temp = head;
        ListNode*startkth = nullptr;
        ListNode*endkth = head;
        while(temp!=nullptr){
            sz++;
            if(sz==k){
                startkth = temp;
            }
            temp = temp->next;

        }
        if(k>sz) return head;
        int kend = sz-k;
        int i = 0;
        while(i<kend && endkth !=nullptr &&endkth->next !=nullptr){
            i++;
            endkth=endkth->next;
        }
        swap(startkth->val, endkth->val);
        
        return head;
    }
};