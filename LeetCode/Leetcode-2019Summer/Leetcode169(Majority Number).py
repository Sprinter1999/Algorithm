class Solution:
    def majorityElement(self, nums) -> int:
        dic={}
        for num in nums:
            dic[num]=dic.get(num,0)+1
            #guess,dic.get(num,0)=dic.get(num,0)+1 is non-existential,for in syntax field,we can't assign to function call
            
        for num in nums:
            if dic.get(num,0)>=len(nums)/2:
                return num