# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
        
class Solution:
    def isLeftRightSym(self, left, right):
        if left is None and right is None:
            return True
        if left is None or right is None:
            return False
        if left.val !=right.val:
            return False
        return self.isLeftRightSym(left.left, right.right) and self.isLeftRightSym(right.left, left.right)


    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if root is None:
            return True
        return self.isLeftRightSym(root.left, root.right)