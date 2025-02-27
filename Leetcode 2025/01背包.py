


def pack(weights: list, values: list, n: int, w: int) -> int:
    
    # 其中 dp[i][j] 表示前 i 件物品重量不超过 j 的情况下能达到的最大价值。
    dp = [[0] * (w + 1) for _ in range(n + 1)]
    for i in range(1, n + 1):
        
        # 取出第i个物品的重量和价值
        weight, value = weights[i - 1], values[i - 1]
        
        
        for j in range(1, w + 1):
            if j >= weight:
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight] + value)
            else:
                dp[i][j] = dp[i - 1][j]
    return dp[n][w]