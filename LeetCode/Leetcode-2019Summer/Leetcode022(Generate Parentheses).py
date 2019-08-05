# 剪枝
class Solution:
    def generateParenthesis(self, n: int):
        self.list=[]
        self._gen(0,0,n,"")
        return self.list
    
    def _gen(self,left,right,n,result):
        if left==n and right==n:
            self.list.append(result)
            return
        if left<n:
            self._gen(left+1,right,n,result+"(")
        if left > right and right <n:
            self._gen(left,right+1,n,result+")")