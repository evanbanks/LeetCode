from typing import Optional

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        pres: ListNode = None
        while head:
            next: ListNode = head.next
            head.next = pres
            pres = head
            head = next
        return pres
            
        