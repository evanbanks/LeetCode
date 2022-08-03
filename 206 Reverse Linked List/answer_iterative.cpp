class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pres = nullptr;
        while (head) {
            ListNode* next = head -> next;
            head -> next = pres;
            pres = head;
            head = next;
        }
        return pres;
    }
};