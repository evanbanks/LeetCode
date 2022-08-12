class Solution {
public:
    ListNode *detectCycle(ListNode* const head) {
        ListNode* slow = head, * fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next; 
            if (slow == fast) {
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
         }
        return nullptr;
        
    }
};