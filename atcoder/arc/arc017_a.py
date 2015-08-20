def miller_rabin(n):
    """ primality Test
        if n < 3,825,123,056,546,413,051, it is enough to test 
        a = 2, 3, 5, 7, 11, 13, 17, 19, and 23.
        Complexity: O(log^3 n)
    """
    if n == 2: return True
    if n <= 1 or not n&1: return False

    primes = [2, 3, 5, 7, 11, 13, 17, 19, 23]

    d = n - 1
    s = 0
    while not d&1:
        d >>= 1
        s += 1

    for prime in primes:
        if prime >= n: break
        x = pow(prime, d, n)
        if x == 1: continue
        for r in range(s):
            if x == n - 1: break
            if r + 1 == s: return False
            x = x * x % n
    return True

print('YES' if miller_rabin(int(input())) else 'NO')
