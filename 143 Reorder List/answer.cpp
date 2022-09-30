ListNode* reverse(ListNode* n){
  if (!n || !n->next){
    return n;
  }
  ListNode* head = reverse(n->next);
  n->next->next = n;
  n->next = nullptr;
  return head;
}


class Solution {
public:
    void reorderList(ListNode* head) {
      if (!head->next) return;
      ListNode* fast = head, *slow = head;
      while (fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
      }
      slow->next = reverse(slow->next);
      fast = head;
      ListNode* temp = slow->next;
      slow->next = nullptr;      
      slow = temp;
      while(slow){
        temp = slow->next;
        slow->next = fast->next;
        fast->next = slow;
        slow = temp;
        fast = fast->next->next;
      }
    }
};