class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums)

        while left < right:
            mid = (left+right)//2
            mid_val = nums[mid]
            if mid_val == target:
                return mid
            elif mid_val > target:
                right = mid
            else:
                left = mid+1
            
        return -1