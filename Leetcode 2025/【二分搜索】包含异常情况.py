

# input： sorted list, target
# output: initial place, last place (bad case: -1, -1)

def scan(nums:list, target:int): 
    ans = [-1, -1]
    
    n = len(nums)
    
    l, r= 0, n
    
    #TODO: find the left end
    while l<=r:
        mid = (l+r)//2
        if  target<=nums[mid]:
            r=mid-1
        else:
            l=mid+1
    
    l_end = l
    
    if nums[l_end]!=target:
        print("not found")
        print(ans)
        return
    
    #TODO: find the right end
    l, r= 0,n
    while l<=r:
        mid = (l+r)//2
        if target<nums[mid]:
            r=mid-1
        else:
            l=mid+1
    
    r_end= r
    
    # 如果l_end r_end合法位于数组中间
    ans= [l_end, r_end]

    print(ans)
    return ans




nums = [1,2,2,2,4,5]
target = 2

bad_nums = [0,1,1,1,1,8]

scan(nums, target)
        
    
    
    
