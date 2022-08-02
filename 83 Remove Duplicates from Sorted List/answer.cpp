class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* temp = head;
        while (temp){
            while (temp->next && temp->val == temp->next->val){
                temp->next = temp->next->next;
            }
            temp = temp->next;
        }
        return head;
    }
};