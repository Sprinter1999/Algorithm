class Solution:
        
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid[0]:return 0
        self.dx=[-1,1,0,0]
        self.dy=[0,0,-1,1]
        self.max_x=len(grid)
        self.max_y=len(grid[0])
        self.grid=grid
        self.visited=set()
        return sum([self.floodfill_DFS(i,j) for i in range(self.max_x) for j in range(self.max_y)])
    
    def floodfill_DFS(self,x,y):
        if not self._is_valid(x,y):
            return 0
        self.visited.add((x,y))
        for k in range(4):
            self.floodfill_DFS(x+self.dx[k],y+self.dy[k])
        return 1
    
    def _is_valid(self,x,y):
        if x<0 or x>=self.max_x or y<0 or y>=self.max_y:
            return False
        if self.grid[x][y]=='0' or ((x,y) in self.visited):
            return False
        return True