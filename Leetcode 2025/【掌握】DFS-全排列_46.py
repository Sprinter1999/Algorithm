class Solution:
    def dfs(self,nums,level,ans):
        if level==len(nums)-1:
            ans.append(nums[:])
            return
        
        for i in range(level,len(nums)):
            nums[i],nums[level] = nums[level], nums[i]
            self.dfs(nums,level+1, ans)
            nums[i],nums[level] = nums[level], nums[i]

    def permute(self, nums: List[int]) -> List[List[int]]:
        ans = []
        self.dfs(nums,0,ans)
        return ans