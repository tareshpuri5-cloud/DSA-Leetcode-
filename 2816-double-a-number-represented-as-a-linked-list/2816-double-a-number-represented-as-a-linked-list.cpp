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
    void reverse(ListNode*&head){
        ListNode*prev=nullptr;
        ListNode*curr = head;
        ListNode*forw=nullptr;
        while(curr!=nullptr){
            forw=curr->next;
            curr->next =prev;
            prev = curr;
            curr = forw;
        }
        head = prev;
    }
    ListNode* doubleIt(ListNode* head) {
        reverse(head);
        int carry=0;
        ListNode*temp = head;
        ListNode*prev=nullptr;
        while(temp!=nullptr){
            int prod = temp->val*2 + carry;
            temp->val = prod%10;
            carry = prod/10;
            prev = temp;
            temp = temp->next;
        }
        if(carry>0){
            prev->next=new ListNode(carry);
        }
        reverse(head);
        return head;

    }
};