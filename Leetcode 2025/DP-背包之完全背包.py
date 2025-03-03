
def pack(weights: list, values: list, n: int, w:int):
    dp = [[0] * (w+1) for _ in range(n+1)]
    
    for i in range(1, n+1):
        
        weight, value = weights[i-1], values[i-1]
        
        for j in range(1,w+1):
            if j >= weight:
                dp[i][j] = max(dp[i-1][j], dp[i][j-weight] + value)
            else:
                dp[i][j] = dp[i-1][j]

    return dp[n][w]