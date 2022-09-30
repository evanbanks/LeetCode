ListNode* reverse(ListNode* n){
  if (!n->next){
    return n;
  }
  ListNode* head = reverse(n->next);
  n->next->next = n;
  n->next = nullptr;
  return head;
}


class Solution {
public:
    bool isPalindrome(ListNode* head) {
    if (!head->next) return true;
    ListNode* fast = head->next, *slow = head;
    while (fast && fast->next){
      fast = fast->next->next;
      slow = slow->next;
    }
    slow->next = reverse(slow->next);
    slow = slow->next;
    fast = head;
    while (slow){
      if (fast->val != slow->val) return false;
      fast = fast->next;
      slow = slow->next;
    }
    return true;
    }
};