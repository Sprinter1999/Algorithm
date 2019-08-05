# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

#最容易想到的方法就是中序遍历是升序
class Solution:
    def isValidBST(self, root:TreeNode) -> bool:
        inorder=self.inorder(root)
        return inorder ==list(sorted(set(inorder)))
    def inorder(self,root):
        if root is None:
            return []
        return self.inorder(root.left) + [root.val,]+self.inorder(root.right)
#为减少时间复杂度与空间复杂度，才用递归的方式优化
class Solution_2:
    def isValidBST(self,root):
        self.prev=None
        return self.helper(root)
    def helper(self,root):
        if root is None:
            return True
        if not self.helper(root.left):
            return False
        if self.prev and self.prev.val>=root.val:
            return False
        self.prev=root
        return self.helper(root.right)