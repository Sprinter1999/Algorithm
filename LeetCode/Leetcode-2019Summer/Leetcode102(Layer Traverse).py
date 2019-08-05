# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

import collections

# BFS solution
class Solution:
    def levelOrder(self, root: TreeNode): # -> List[List[int]]
        # BFS solution
        if not root: return []
        
        result=[]
        queue=collections.deque() #双端队列
        queue.append(root)
        
        # visited=set(root) # Because Tree's structure
        
        while queue:
            level_size=len(queue)
            current_level=[]
            
            for _ in range(level_size):
                node=queue.popleft()
                current_level.append(node.val)
                
                if node.left:queue.append(node.left)
                if node.right:queue.append(node.right)
                    
            result.append(current_level)
            
        return result
# DFS solution
class Solution2:
    def levelOrder(self,root):
        if not root:return []
        self.result=[]
        self.dfs(root,0)
        return self.result
    def dfs(self,node,level):
        if not node:return 
        if len(self.result)<level+1:
            self.result.append([])
        
        self.result[level].append(node.val)

        self.dfs(node.left,level+1)
        self.dfs(node.right,level+1)
