# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def reconstruct(self, io_map, po, l, r, mid_po):
        if l>r:
            return None
        
        mid_val = po[mid_po]
        mid_io = io_map[mid_val]

        left_len = mid_io - l +1
        node = TreeNode(mid_val)
        node.left = self.reconstruct(io_map, po, l, mid_io-1, mid_po+1)
        node.right = self.reconstruct(io_map, po, mid_io+1, r, mid_po + left_len)
        return node

    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        io_map = {val: i for i, val in enumerate(inorder)}
        return self.reconstruct(io_map, preorder,0, len(preorder)-1, 0)
