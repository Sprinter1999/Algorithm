class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        from collections import defaultdict, deque
        g = defaultdict(list)
        indeg = [0] * numCourses
        for a, b in prerequisites:
            g[b].append(a)
            indeg[a] += 1


        ans = []

        q = deque(i for i, x in enumerate(indeg) if x == 0)
        
        
        while q:
            i = q.popleft()
            ans.append(i)

            # j 为 每一个后续要上的课
            for j in g[i]:
                indeg[j] -= 1
                if indeg[j] == 0:
                    q.append(j)
                    
        return ans if len(ans) == numCourses else []
