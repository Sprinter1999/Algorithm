def coinChange(coins: list, amount: int) -> int:
    dp = [0] + [amount + 1] * amount
    for i in range(1, amount + 1):
        for coin in coins:
            if i >= coin:
                dp[i] = min(dp[i], dp[i - coin] + 1)
    return dp[amount] if dp[amount] != amount + 1 else -1



def coinChange_2d(coins: list, amount: int) -> int:
    dp = [[0] * (amount + 1) for _ in range(len(coins) + 1)]
    for i in range(1, len(coins) + 1):
        for j in range(1, amount + 1):
            if j < coins[i - 1]:
                dp[i][j] = dp[i - 1][j]
            else:
                dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1)
    return dp[len(coins)][amount] if dp[len(coins)][amount] != amount + 1 else -1
