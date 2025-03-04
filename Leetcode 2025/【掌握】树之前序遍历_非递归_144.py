# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# 递归
# class Solution:
#     def dfs(self, root):
#         if not root:
#             return
        
#         self.ans.append(root.val)
#         self.dfs(root.left)
#         self.dfs(root.right)


#     def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
#         self.ans=[]

#         self.dfs(root)

#         return self.ans


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        po = []
        
        if root is None:
            return po

        s= [root]
        
        while len(s)>0:
            node = s.pop()
            po.append(node.val)
            
            #TODO: 此处注意先右后左，保证左子树先遍历
            if node.right is not None:
                s.append(node.right)
            if node.left is not None:
                s.append(node.left)
            
        return po