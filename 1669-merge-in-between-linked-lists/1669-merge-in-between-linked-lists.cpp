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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* left = NULL;
        ListNode* right = NULL;
        ListNode* it = list1;
        for (int i = 0; i <= b; i++) {
            right = it;
            if (i == a - 1) {
                left = it;
            }
            it = it->next;
        }
        if (left != NULL) {
            left->next = list2;
        }
        ListNode* head = list1;
        ListNode* temp = NULL;
        for (it = list2; it != NULL; it = it->next) {
            temp = it;
        }
        temp->next = right->next;
        return head;
    }
};

auto boostio = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();