import collections
dx=[-1,1,0,0]
dy=[0,0,1,-1]
def floodfill_BFS(self,x,y):
    if not self._is_valid(x,y):
        return
    
    self.visited.add((x,y))

    queue=collections.deque()
    queue.append((x,y))

    while queue:
        cur_x,cur_y=queue.popleft()
        for i in range(4):
            new_x,new_y=x+dx[i],y+dy[i]
            if self._is_valid(new_x,new_y):
                self.visited.add((new_x,new_y))
                queue.append((new_x,new_y))