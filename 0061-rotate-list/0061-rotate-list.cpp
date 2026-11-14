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
    ListNode* rotateRight(ListNode* head, int k) {
       if(head == nullptr || head->next == nullptr || k==0) return head;
       ListNode*temp=head;
       ListNode*temp2=head;

       int sz=1;
       while(temp->next!=nullptr){
        temp = temp->next;
        sz++;
       } 
        if(k%sz == 0) return head;
       k = k%sz;
       int endkth = sz-k;
       int i=1;
       while(i<endkth){
            i++;
            temp2=temp2->next;
        }
        ListNode*newHead = temp2->next;
        temp2->next=nullptr;
        temp->next=head;
        head = newHead;

        return head;
    }
};