
def sort(nums:list)->list:
    if len(nums) <= 1:
        return nums

    n = len(nums)
    import random
    pivot = random.randint(1,n)
    pivot_val = nums[pivot]
    
    left = [x for x in nums[1:] if x < pivot_val]
    eq = [x for x in nums[1:] if x == pivot_val]
    right = [x for x in nums[1:] if x > pivot_val]

    return sort(left) + eq + sort(right)