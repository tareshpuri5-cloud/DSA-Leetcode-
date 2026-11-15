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
    ListNode* mergeNodes(ListNode* head) {
        ListNode*btwnode=head->next;
        ListNode*temp=head->next;
        int sum=0;

        while(temp!=nullptr){

            if(temp->val==0){
                btwnode->val=sum;
                temp=temp->next;
                 btwnode->next=temp;
                sum =0;
                btwnode=btwnode->next;
            }else{
                sum = sum+temp->val;
                temp=temp->next;

            }
        }    
        return head->next;

    }
};