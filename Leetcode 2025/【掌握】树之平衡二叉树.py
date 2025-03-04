# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self,root):
        if root is None:
            return 0
        else:
            left_height = self.dfs(root.left)+1
            right_height = self.dfs(root.right)+1

            ans = abs(left_height-right_height)
            if ans>self.maxdiv:
                self.maxdiv=ans

            return max(left_height,right_height)

    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        self.maxdiv = 0
        self.dfs(root)
        if self.maxdiv>1:
            return False
        else:
            return True