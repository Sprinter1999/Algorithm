# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        prevhead = ListNode()
        prev = prevhead

        while l1 and l2:

            if l1.val<=l2.val:
                prev.next = l1
                l1 = l1.next
            else:
                prev.next = l2
                l2 = l2.next
            
            prev = prev.next
        
        if l1 is not None:
            prev.next=l1
        else:
            prev.next=l2
        
        return prevhead.next