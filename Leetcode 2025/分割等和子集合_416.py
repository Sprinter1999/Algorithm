class Solution:
    def canPartition(self, nums: list) -> bool:
        summ = sum(nums)
        n = len(nums)

        if summ & 1 ==1:
            return False
        
        target = summ // 2

        dp = [[False for _ in range(target+1)] for _ in range(n+1) ]
        
        dp[0][0]=True

        for i in range(1, n+1):
            for j in range(target+1):

                if j < nums[i-1]:
                    dp[i][j]=dp[i-1][j]
                else:
                    dp[i][j] = dp[i - 1][j] or dp[i - 1][j - nums[i - 1]]
        
        return dp[n][target]