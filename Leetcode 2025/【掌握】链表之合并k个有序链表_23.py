# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeKLists(self, lists: list[Optional[ListNode]]) -> Optional[ListNode]:
        stores = []

        for each_list in lists:

            cur = each_list
            while cur is not None:
                stores.append(cur.val)
                cur = cur.next

        import heapq
        heapq.heapify(stores)
        sum_n = len(stores)

        #    处理空列表的情况
        if sum_n == 0:
            return None

        # 创建头节点
        head = ListNode(heapq.heappop(stores))
        cur = head

        while stores:
            new_node = ListNode(heapq.heappop(stores))
            cur.next = new_node
            cur = new_node

        return head