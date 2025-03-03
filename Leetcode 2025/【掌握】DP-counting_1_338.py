
## 给定一个非负整数 n，求从 0 到 n 的所有数字的二进制表达中，分别有多少个 1。


def countBits(n: int) -> list[int]:
    dp = [0] * (n + 1)
    for i in range(1, n + 1):
        dp[i] = dp[i - 1] + 1 if i & 1 else dp[i >> 1]
    return dp