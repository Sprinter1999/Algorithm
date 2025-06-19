class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        n = len(nums)
        if n==1:
            return nums[0]
        
        dp = [0 for i in range(n)]
        for i in range(n):
            dp[i]=nums[i]

        for i in range(1,n):
            dp[i]=max(nums[i],nums[i]+dp[i-1])
        
        return max(dp)