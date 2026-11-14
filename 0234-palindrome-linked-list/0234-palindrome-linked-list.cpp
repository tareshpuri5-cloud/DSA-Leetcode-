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
    bool isPalindrome(ListNode*&head,ListNode*&head2,ListNode*slow){
        while(head2!=nullptr){
            if(head->val==head2->val){
                head= head->next;
                head2= head2->next;
            }else{
                return false;
            }
            
        }
        return true;
    }
    void revHalf(ListNode*&head,ListNode*&head2,ListNode*&slow){
        if(slow->next==nullptr) return;
        ListNode* prev = nullptr;
        ListNode* curr = head2;
        ListNode* forw = nullptr;
        while (curr != nullptr) {
            forw = curr->next;   // 1. Save next node before breaking the link
            curr->next = prev;   // 2. Reverse current node's pointer
            prev = curr;         // 3. Advance prev forward
            curr = forw;         // 4. Advance curr forward
        }
        head2 = prev;  
    }
    bool isPalindrome(ListNode* head) {
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast != nullptr && fast->next != nullptr){
            fast=fast->next;
            if(fast->next!=nullptr){
                fast = fast->next;
                slow = slow->next;
            }
        }
        if(slow->next!=nullptr){
            slow=slow->next;
        }
        ListNode*head2=slow;
        revHalf(head,head2,slow);
        return isPalindrome(head,head2,slow);
        
    }
};