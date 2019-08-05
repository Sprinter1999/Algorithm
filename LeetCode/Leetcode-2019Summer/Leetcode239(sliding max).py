class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        if not nums: return []
        window,res=[],[]
        #window stores indices,and res stores result
        for i,x in enumerate(nums):
            if i>=k and window[0]<=i-k:
                window.pop(0)
            while window and nums[window[-1]]<=x:
                window.pop()
            window.append(i)
            if i>=k-1:
                res.append(nums[window[0]])
        return res