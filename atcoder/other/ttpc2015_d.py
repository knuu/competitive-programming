import itertools


def miller_rabin(n):
    """ primality Test
        if n < 3,825,123,056,546,413,051, it is enough to test
        a = 2, 3, 5, 7, 11, 13, 17, 19, and 23.
        Complexity: O(log^3 n)
    """
    if n == 2:
        return True
    if n <= 1 or not n & 1:
        return False

    primes = [2, 3, 5, 7, 11, 13, 17, 19, 23]

    d = n - 1
    s = 0
    while not d & 1:
        d >>= 1
        s += 1

    for prime in primes:
        if prime >= n:
            continue
        x = pow(prime, d, n)
        if x == 1:
            break
        for r in range(s):
            if x == n - 1:
                break
            if r + 1 == s:
                return False
            x = x * x % n
    return True


S = input()
str_set = set(list(S))
if len(str_set) > 5:
    print(-1)
    exit(0)
for l in itertools.permutations('13579'):
    N = S.translate(str.maketrans(dict(zip(str_set, l))))

    if miller_rabin(int(N)):
        print(N)
        break
else:
    print(-1)
