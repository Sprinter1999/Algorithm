def countPrimes(n: int) -> int:
    if n <= 2:
        return 0
    
    primes = [True for _ in range(n)]
    count = n - 2 # 去掉不是质数的1
    
    for i in range(2, n):
        if primes[i]:
            for j in range(2 * i, n, i):
                if primes[j]:
                    primes[j] = False
                    count -= 1
                    
    return count