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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*temp = head;
        int sz=0;
        while(temp!=nullptr){
            temp=temp->next;
            sz++;
        }
        if(k>sz || k==0 || head==nullptr || head->next==nullptr ||k<=1) return head;

        ListNode* newHead = nullptr;   
        ListNode* prevTail = nullptr;
        ListNode*curr=head;
        while(sz>=k){
            ListNode*prev=nullptr;
            ListNode*forw=nullptr;
            int i=0;
            ListNode*tail=curr;
            while(i<k){
                i++;
                forw = curr->next;
                curr->next = prev;
                prev = curr; 
                curr = forw;
            }
            if(newHead==nullptr){
                newHead=prev;
            }else{
                prevTail->next=prev;
            }
            tail->next=curr;
            prevTail = tail;
            sz -= k;
        }
        return newHead;
        
    }
};