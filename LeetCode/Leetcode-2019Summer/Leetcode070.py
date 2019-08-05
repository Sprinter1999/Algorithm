class Solution:
    def climbStairs(self, n: int) -> int:
        f=[1,1]
        if n>=2:
            for i in range(2,n+1):
                f.append(f[i-1]+f[i-2])
        return f[-1]

        #Python的 x,y=y,x可以直接实现交换的功能，不需要中间变量