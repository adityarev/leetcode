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
auto boostio = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
private:
    bool helper(ListNode** cross, ListNode* curr) {
        if (curr == NULL) {
            return true;
        }
        bool another_equal = helper(cross, curr->next);
        bool equal = curr->val == (*cross)->val;
        *cross = (*cross)->next;
        return equal && another_equal;
    }

public:
    bool isPalindrome(ListNode* head) {
        ListNode* cross = head;
        return helper(&cross, head);
    }
};