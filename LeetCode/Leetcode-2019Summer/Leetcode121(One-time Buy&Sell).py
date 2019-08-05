class Solution:
    def maxProfit(self, prices) -> int:
        if len(prices)<1:
            return 0
        
        min_before=prices[0]
        
        profit=0
        for i in range(1,len(prices)):
            if prices[i]>min_before:
                profit=max(profit,prices[i]-min_before)
            else:
                min_before=prices[i]
        return profit
    
    # 增强版冒泡排序，不过只是在O(N)时间内的就地算法
    
    # 以下是简明算法 Java
    
#     class Solution {
#     public int maxProfit(int[] prices) {
#          if (prices == null || prices.length < 1) {
#             return 0;
#         }
#         int bene = 0;
#         for(int i = 0;i < prices.length;++i){
#             for(int j = i + 1;j < prices.length;++j){
#                 if(prices[j] - prices[i] > bene)
#                     bene = prices[j] - prices[i];
#             }
#         }
#         return bene;
#     }
# }