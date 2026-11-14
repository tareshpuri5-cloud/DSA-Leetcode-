/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sz1=0;
        int sz2=0;
        ListNode*temp1=headA;
        ListNode*temp2=headB;

        while(temp1!=nullptr){
            sz1++;
            temp1=temp1->next;
        }
        while(temp2!=nullptr){
            sz2++;
            temp2=temp2->next;
        }
        int gap=abs(sz1-sz2);
        while(gap>0){
            if(sz1>sz2){
                headA=headA->next;
            }else{
                headB=headB->next;
            }
            gap--;
        }
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;

    }
};