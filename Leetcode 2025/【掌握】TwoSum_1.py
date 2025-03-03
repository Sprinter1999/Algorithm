def twoSum(nums: list[int], target: int) -> list[int]:
    cache = dict() # <值，位置>
    
    for i, num1 in enumerate(nums):
        num2 = target - num1
        if num2 in cache:
            return [cache[num2], i]
        cache[num1] = i
    
    return []