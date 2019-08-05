#反转链表
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# class Solution:
#     def reverseList(self, head: ListNode) -> ListNode:
#         cur,prev=head,None
#         while cur:
#             cur.next,prev,cur=prev,cur,cur.next
#         return prev