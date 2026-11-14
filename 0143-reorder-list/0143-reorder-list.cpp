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
    void reorder(ListNode*&head,ListNode*&head2){
        ListNode*temp=head2;
        while(head2!=nullptr){
            ListNode*temp=head2;
            head2=head2->next;
            temp->next = head->next;
            head->next =temp;
            head = temp->next;

        }
    }
    void revHalf(ListNode*&head2){
        ListNode*prev=nullptr;
        ListNode*curr=head2;
        ListNode*forw=nullptr;
        while(curr!=nullptr){
            forw=curr->next;//store
            curr->next=prev;//rev
            prev = curr;//adv
            curr = forw;//adv
        }
        head2=prev;
    }
    void reorderList(ListNode* head) {
            ListNode*fast = head;
            ListNode*slow = head;
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next;
            if(fast->next!=nullptr){
                slow=slow->next;
                fast=fast->next;
            }
        }
        ListNode*head2=slow->next;
        slow->next = nullptr;
        revHalf(head2);
        reorder(head,head2);

    }
};