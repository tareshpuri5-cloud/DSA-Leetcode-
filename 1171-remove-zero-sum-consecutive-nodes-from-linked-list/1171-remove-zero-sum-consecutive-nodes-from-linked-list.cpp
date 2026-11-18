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
    ListNode* removeZeroSumSublists(ListNode* head) {
        if (head == nullptr) return nullptr;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        unordered_map<int, ListNode*> mp;
        int sum = 0;
        ListNode* temp = dummy;

        while (temp != nullptr) {
            sum = sum + temp->val;
            mp[sum] = temp;
            temp = temp->next;
        }

        sum = 0;
        temp = dummy;

        while (temp != nullptr) {
            sum = sum + temp->val;
            temp->next = mp[sum]->next;
            temp = temp->next;
        }

        return dummy->next;
    }
};