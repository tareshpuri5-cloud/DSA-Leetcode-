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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            if(list1==nullptr && list2==nullptr){
                return nullptr;
            }
            if(list1==nullptr){
                return list2;
            }
            if(list2==nullptr){
                return list1;
            }
            if (list2->val < list1->val) {
                //making sure that l1 starts with smaller value
                ListNode* Temp = list1;
                list1 = list2;
                list2 = Temp;
            }
        ListNode* prev1 = list1;        //temp se ek step peeche hmesha
        ListNode* temp1 = list1->next;  
        ListNode* temp2 = list2;        

        while(temp1 != nullptr && temp2 != nullptr){   
            if(temp2->val <= temp1->val ){
                ListNode*prev2 = temp2->next;
                prev1->next = temp2;
                temp2->next = temp1;
                prev1=temp2;
                temp2 = prev2;

            }else{
                prev1=temp1;
                temp1=temp1->next;
            }
        }
        if (temp2 != nullptr) {
            prev1->next = temp2;
        }
        return list1;
    }    
};