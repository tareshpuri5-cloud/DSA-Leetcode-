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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode*temp = head;
        ListNode*start = nullptr;
        ListNode*end = nullptr;
        ListNode*prevHead = nullptr;
        ListNode*prevTail = nullptr;
        int pos = 1;
        while(temp!=nullptr && pos<=right){
            if(pos==left-1){
                prevHead = temp;
            }
            if(pos==left){
                start = temp;
            }
            if(pos==right){
                end = temp;
                prevTail=temp->next;
            }
            temp=temp->next;
            pos++;
        }
        int count = right-left+1;
        ListNode*prev=prevTail;
        ListNode*curr=start;
        ListNode*forw=nullptr;
        while(count!=0){
            count--;
            forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
        }
        if(prevHead!=nullptr){
            prevHead->next=prev;
        }else{
            head=prev;
        }
        return head;
    }
};