import sys
from sys import stdin
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        if not head:
            return True
        # 找中点
        slow = fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        # 反转后半部分
        prev = None
        curr = slow
        while curr:
            next_node = curr.next
            curr.next = prev
            prev = curr
            curr = next_node
        # 比较前后两部分
        left = head
        right = prev
        while right:
            if left.val != right.val:
                return False
            left = left.next
            right = right.next
        return True

def build_linked_list(nums):
    if not nums:
        return None
    head = ListNode(nums[0])
    curr = head
    for num in nums[1:]:
        curr.next = ListNode(num)
        curr = curr.next
    return head

def main():
    # 手动添加测试样例
    test_cases = [
        ([1, 2, 2, 1], True),
        ([1, 2], False),
        ([1], True),
        ([1, 3, 2, 3, 1], True)
    ]
    
    for nums, expected in test_cases:
        head = build_linked_list(nums)
        solution = Solution()
        result = solution.isPalindrome(head)
        print(f"输入: {nums}, 输出: {result}, 预期: {expected}")
        assert result == expected, f"测试失败: 输入{nums}"

if __name__ == "__main__":
    main()