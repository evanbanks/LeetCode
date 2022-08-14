class Solution {
public:
    ListNode* middleNode(ListNode* const head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};