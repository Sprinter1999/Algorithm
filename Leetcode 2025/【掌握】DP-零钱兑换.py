def coinChange(coins: list, amount: int) -> int:
    dp = [0] + [amount + 1] * amount
    for i in range(1, amount + 1):
        for coin in coins:
            if i >= coin:
                dp[i] = min(dp[i], dp[i - coin] + 1)
    return dp[amount] if dp[amount] != amount + 1 else -1



class Solution:
    def coinChange(self,coins, amount):
        n = len(coins)
        if amount == 0:
            return 0
        # 初始化二维dp数组，默认值为amount+1（极大值）
        dp = [[amount + 1] * (amount + 1) for _ in range(n + 1)]
        dp[0][0] = 0  # 初始状态：金额0需要0个硬币
        
        for i in range(1, n + 1):
            coin = coins[i-1]
            for j in range(amount + 1):
                if j < coin:
                    # 当前金额不足以使用该硬币，继承前i-1种硬币的结果
                    dp[i][j] = dp[i-1][j]
                else:
                    # 选择是否使用当前硬币，取最小值
                    dp[i][j] = min(dp[i-1][j], dp[i][j - coin] + 1)
        
        result = dp[n][amount]
        return result if result != amount + 1 else -1