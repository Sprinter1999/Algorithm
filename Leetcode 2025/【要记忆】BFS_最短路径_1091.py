class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        if grid[0][0] == 1:
            return -1

        n = len(grid)
        dist = [[inf] * n for _ in range(n)]
        dist[0][0] = 1

        queue = deque([(0, 0)])

        while queue:
            x, y = queue.popleft()
            if x == y == n - 1:
                return dist[x][y]

            for dx in range(-1, 2):
                for dy in range(-1, 2):
                    if x + dx < 0 or x + dx >= n or y + dy < 0 or y + dy >= n:  # 越界
                        continue
                    if (
                        grid[x + dx][y + dy] == 1
                        or dist[x + dx][y + dy] <= dist[x][y] + 1
                    ):  # 单元格值不为 0 或已被访问
                        continue

                    dist[x + dx][y + dy] = dist[x][y] + 1
                    queue.append((x + dx, y + dy))
        return -1
