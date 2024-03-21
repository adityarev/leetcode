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
private:
    ListNode* helper(ListNode* prev, ListNode* curr) {
        if (curr == NULL) {
            return prev;
        }
        ListNode* next = helper(curr, curr->next);
        curr->next = prev;
        return next;
    }
    
public:
    ListNode* reverseList(ListNode* head) {
        return helper(NULL, head);
    }
};