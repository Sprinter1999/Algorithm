class solution:
    def twoSum(self,nums,target):
        hash_map=dict() 
        # Python字典初始化{}性能比dict()好
        for i,x in enumerate(nums):
            if target-x in hash_map:
                return [i,hash_map[target-x]]
            hash_map[x]=i
 