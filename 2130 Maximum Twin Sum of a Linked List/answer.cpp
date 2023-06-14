class Solution {
    ListNode* reverse(ListNode* const head){
        if (!head->next) return head;
        ListNode* nh = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return nh;
    }
public:
    int pairSum(ListNode* const head) {
        ListNode* slow = head, *fast = head->next;
        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverse(slow->next);
        slow = slow->next;
        fast = head;
        int sum = 0;
        while (slow){
            sum = std::max(sum,fast->val+slow->val);
            slow = slow->next;
            fast = fast->next;
        }
        return sum;
    }
};
