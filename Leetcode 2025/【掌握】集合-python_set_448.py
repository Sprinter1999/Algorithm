# 定义两个集合
set1 = {1, 2, 3, 4}
set2 = {3, 4, 5, 6}

# 计算交集
intersection = set1 & set2
print("交集:", intersection)

# 计算并集
union = set1 | set2
print("并集:", union)

# 返回值也是一个set()


class Solution:
    def findDisappearedNumbers(self, nums: list[int]) -> list[int]:
        
        nums_set = set(nums)
        max_one = max(nums)
        n = len(nums)


        A = list(range(1, n+1))
        set_A = set(A)

        target = set_A - nums_set

        return list(target)

