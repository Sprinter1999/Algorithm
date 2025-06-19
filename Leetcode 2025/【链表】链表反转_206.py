# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        head_prev = None
        while head is not None:
            head_next = head.next
            head.next = head_prev
            head_prev = head
            head = head_next
        
        return head_prev