def trailingZeroes(n: int) -> int:
    return 0 if n == 0 else n // 5 + trailingZeroes(n // 5)