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
    void size(ListNode*head,int &count){
        ListNode*temp = head;
        while(temp!=nullptr){
            count++;
            temp=temp->next;
        }
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0;
        size(head,count);
        int fstart = count-n+1;
        ListNode*temp = head;
        ListNode*forw = head->next;
        if(n==count){
            head = head->next;
            delete temp;
        }
        if(n<count){
            int i=0;
            while(i<fstart-2){
                i++;
                temp=temp->next;
                forw = forw->next;
            }
                temp->next = forw->next;
                delete forw;
        }
        return head;
    }
};