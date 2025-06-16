# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
        
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        start_1, start_2 = l1, l2
        traverse_1, traverse_2 = '', ''
        while start_1 !=None:
            cur_val = start_1.val
            traverse_1 += str(cur_val)
            start_1 = start_1.next
        
        while start_2 !=None:
            cur_val = start_2.val
            traverse_2 += str(cur_val)
            start_2 = start_2.next
        
        ans_1, ans_2 = int(traverse_1[::-1]), int(traverse_2[::-1])

        ans = str(ans_1+ans_2)
        len_ans = len(ans)
        
        # 创建一个新链表，每个节点存储一个数字，分别为ans的每一位
        head = ListNode(int(ans[0]))

        for i in range(1, len_ans):
            cur_node = ListNode(int(ans[i]))
            cur_node.next = head
            head = cur_node
        
        return head





        