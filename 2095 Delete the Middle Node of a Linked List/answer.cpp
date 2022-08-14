class Solution {
public:
    ListNode* deleteMiddle(ListNode* const head) {
        ListNode* fast = head;
        ListNode* slow = head;
        if (fast && fast->next){
            fast = fast->next->next;
        } else {
            return nullptr;
        }
        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};