# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flipTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return root 
        root.left, root.right = root.right, root.left 
        self.flipTree(root.left)
        self.flipTree(root.right)
        return root
