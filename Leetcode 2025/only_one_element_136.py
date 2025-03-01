def singleNumber(nums: list[int]) -> int:
    single = 0
    for num in nums:
        single = single ^ num
        return single