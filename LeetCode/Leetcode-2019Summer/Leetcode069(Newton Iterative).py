class Solution:
    def mySqrt(self, x):
        if x <= 1:
            return x 
        hi = x 
        while hi > x/hi:
            hi = (hi+x/hi)//2
        return int(hi)