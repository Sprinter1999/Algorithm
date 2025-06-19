class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        import heapq
        heapq.heapify(nums)

        sorted_seq = [heapq.heappop(nums) for _ in range(len(nums))]

        return sorted_seq[len(nums)-k]