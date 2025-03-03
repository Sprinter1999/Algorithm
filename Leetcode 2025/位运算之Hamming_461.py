class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        diff = x^y
        ans = 0

        while diff !=0:
            ans += diff & 1
            diff = diff >> 1
        
        return ans