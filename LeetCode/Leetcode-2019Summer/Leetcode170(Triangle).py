class Solution:
    def minimumTotal(self, triangle) -> int:
        if not triangle: return 0
        res = triangle[-1]
        
        for i in range(len(triangle)-2,-1,-1):
            for j in range(len(triangle[i])):
                res[j]=min(res[j],res[j+1])+triangle[i][j]
                
        return res[0]
        