class Solution:
    def sumNumbers(self, root: Optional[TreeNode], x=0) -> int:
        if root is None:
            return 0
            
        x = x * 10 + root.val

        if root.left is None and root.right is None:  # root 是叶子节点
            return x
        return self.sumNumbers(root.left, x) + self.sumNumbers(root.right, x)
