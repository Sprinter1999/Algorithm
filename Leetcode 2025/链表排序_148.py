# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        if not head or not head.next: 
            return head
        slow = head
        fast = head
        
        
        # 用快慢指针分成两部分
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        # 找到左右部分, 把左部分最后置空
        mid = slow.next
        slow.next = None
        
        
        # 递归下去
        left = self.sortList(head)
        right = self.sortList(mid)
        # 合并
        return self.merge(left, right)

    def merge(self, left, right):
        #TODO: 将这两个链表合并成一个有序的链表，并返回合并后的链表的头节点
        dummy = ListNode(0)
        p = dummy
        l = left
        r = right

        while l and r:
            if l.val < r.val:
                p.next = l
                l = l.next
                p = p.next
            else:
                p.next = r
                r = r.next
                p = p.next
        if l:
            p.next = l
        if r:
            p.next = r
        return dummy.next