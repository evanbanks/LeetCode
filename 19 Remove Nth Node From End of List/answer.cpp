class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, const int n) {
    if (!head->next) return nullptr;
    ListNode* s = head, *f = head;
    for (int i=0; i<n; ++i){
      f = f->next;
    }
    if (!f) return head->next;
    f = f->next;
    while (f){
      f = f->next;
      s = s->next;
    }
    s->next = s->next->next;
    return head;
  }
};