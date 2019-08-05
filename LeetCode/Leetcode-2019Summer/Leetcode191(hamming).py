class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        count=0
        while(n!=0):
            if(n&1):
                count=count+1
            n>>=1
        return count
        
        #another way is use x=x&x-1 to eliminate the 1s that n has,but its hard to figure out