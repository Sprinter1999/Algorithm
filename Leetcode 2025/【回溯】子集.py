class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans = []
        path = []
        n = len(nums)
        def dfs(i: int) -> None:
            ans.append(path.copy())  # 复制 path
            for j in range(i, n):  # 枚举选择的数字
                path.append(nums[j])
                dfs(j + 1)
                path.pop()  # 恢复现场
        dfs(0)
        return ans

# 枚举子集（答案）的第一个数选谁，第二个数选谁，第三个数选谁，依此类推。
# dfs 中的 i 表示现在要枚举选 nums[i] 到 nums[n−1] 中的一个数，添加到 path 末尾。
# 如果选 nums[j] 添加到 path 末尾，那么下一个要添加到 path 末尾的数，就要在 nums[j+1] 到 nums[n−1] 中枚举了。

