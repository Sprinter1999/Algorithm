class Solution:
    def convertToBase7(self, num: int) -> str:
        neg_flag = num < 0

        ans = ""

        num = abs(num)

        if num==0:
            return str(num)

        while num:
            modular = num % 7
            ans += str(modular)
            num //= 7
        
        ans = ans[::-1]

        if neg_flag:
            return "-"+ans
        else:
            return ans