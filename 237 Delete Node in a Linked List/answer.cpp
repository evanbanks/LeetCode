class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode* u = node->next;
        node->next = u->next;
        delete u;
        
    }
};
