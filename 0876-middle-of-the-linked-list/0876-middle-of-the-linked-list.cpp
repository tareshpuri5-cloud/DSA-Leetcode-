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
    void solve(ListNode*&head,ListNode*&first,ListNode*&second){
        if( second->next == nullptr ) {
            head = first;   
            return ;
        }
        if(second == nullptr ||second->next->next==nullptr || second->next->next->next == nullptr){
            head = first->next;
            return;   
        }
        first = first->next;
        second = second->next->next;
        solve(head,first,second);
       
    }
    ListNode* middleNode(ListNode* head) {
        ListNode*first = head;
        ListNode*second = head;
        solve(head,first,second);
        return head;
    }
};