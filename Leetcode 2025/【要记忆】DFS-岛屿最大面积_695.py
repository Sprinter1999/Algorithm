class Solution:
    def dfs(self, grid, cur_i, cur_j):
        if cur_i<0 or cur_i>=len(grid) or cur_j <0 or cur_j>=len(grid[0]) or grid[cur_i][cur_j]==0:
            return 0
        
        grid[cur_i][cur_j]=0 #置0，防止之后再次遍历增加复杂度

        ans=1
        direction = [-1,0,1,0,-1]

        for ind in range(4):
            next_i, next_j = cur_i+direction[ind], cur_j+direction[ind+1]
            ans += self.dfs(grid,next_i,next_j)
        
        return ans

    def maxAreaOfIsland(self, grid: list[list[int]]) -> int:
        ans=0
        n,m = len(grid), len(grid[0])
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    ans = max(self.dfs(grid,i,j),ans)
        
        return ans