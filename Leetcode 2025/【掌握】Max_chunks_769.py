class Solution:
    def maxChunksToSorted(self, arr: list[int]) -> int:
        chunks, cur_max = 0,0

        for i, num in enumerate(arr):
            cur_max = max(cur_max, num)
            chunks += cur_max == i
        
        return chunks