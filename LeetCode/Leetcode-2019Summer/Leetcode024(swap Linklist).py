#链表交换元素
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# class Solution:
#     def swapPairs(self, head):
#         pre,pre.next=self,head
        
#         while pre.next and pre.next.next:
#             a=pre.next
#             b=a.next
#             pre.next,b.next,a.next=b,a,b.next
#             pre=a
#         return self.next

# reference：
# https://www.wandouip.com/t5i260061/
# Summary：
# Here, pre is the previous node. 
# Since the head doesn't have a previous node, 
# I just use self instead.
# Again, a is the current node and b is the next node.
# To go from pre -> a -> b -> b.next to pre -> b -> a -> b.next, 
# we need to change those three references.
#  Instead of thinking about in what order I change them, 
# I just change all three at once.

# def swapPairs(self,head):
#     result=ListNode(0) #dummy node
#     pre,pre.next=result,head
#     #...剩下的都一样了
