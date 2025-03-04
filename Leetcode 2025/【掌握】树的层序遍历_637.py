# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        level_avg = []

        if root is None:
            return level_avg
        
        from collections import deque
        q = collections.deque()

        q.append(root)
        count = len(q)

        while count >0:
            level_sum =0
            for _ in range(count):
                node = q.popleft()
                level_sum += node.val

                if node.left is not None:
                    q.append(node.left)
                
                if node.right is not None:
                    q.append(node.right)
            
            level_avg.append(level_sum/count)
            count = len(q)
        
        return level_avg