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
    void reverse(ListNode* &head,ListNode*&tail){
        if(head == nullptr || head->next == nullptr){
               tail = head;
                return ;
        } 
        ListNode*curr= head;
        ListNode*forw = curr->next;
        reverse(head->next,tail);
        forw->next = curr;
        head->next = nullptr;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode*tail;
        reverse(head,tail);
        return tail;
    }
};