class Solution {
public:
    ListNode* reverseList(ListNode* n) {
        if (!n || !n->next) return n;
        ListNode* head = reverseList(n->next);
        n->next->next = n;
        n->next = nullptr;
        return head;
    }
};