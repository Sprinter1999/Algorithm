class Solution:
    def canJump(self, nums:list) -> bool:
        max_can_reach = 0
        for i, x in enumerate(nums):
            
            if i > max_can_reach:
                return False
            max_can_reach = max(max_can_reach, i + x)
            print(f"index: {i}, val: {x}, max_readh: {max_can_reach}")

        return True