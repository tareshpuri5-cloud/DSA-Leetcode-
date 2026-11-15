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

    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
       int index=1;
       int minDist=INT_MAX;
       int maxDist =0 ;
       int prevCritical = -1;
       int currCritical = -1;
        int firstCritical = -1;
        ListNode*prev = head;
        ListNode*curr = head->next;
       if (head == nullptr || head->next == nullptr || head->next->next == nullptr) return {-1, -1};
       while(curr->next!=nullptr ){
            if((prev->val > curr->val && curr->next->val > curr->val)||(prev->val < curr->val && curr->next->val < curr->val)){
                int i=index;
                if(prevCritical == 0 ||prevCritical == -1){
                    prevCritical=i;
                    firstCritical=i;
                }else{
                    currCritical = i;
                    minDist=min(minDist,currCritical - prevCritical);
                    prevCritical =i;
                }
            }
            index++;
            prev = curr;
            curr=curr->next;

        }

        if(firstCritical==-1 || currCritical==-1){ 
            return{-1,-1};
        }else{
            return{minDist,currCritical - firstCritical};
        }
    }
};