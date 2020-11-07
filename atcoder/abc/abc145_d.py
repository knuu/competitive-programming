mod = 10**9+7


def inv(x):
    return pow(x, mod - 2, mod)


def nCk(n, k):
    assert 0 <= k <= n
    k = min(k, n - k)
    ret = 1
    for i in range(k):
        ret *= n - i
        ret %= mod
        ret *= inv(i + 1)
        ret %= mod
    return ret


def nHk(n, k):
    assert 1 <= k <= n
    return nCk(n + k - 1, k - 1)


X, Y = map(int, input().split())
mod = 10 ** 9 + 7
if (X + Y) % 3 != 0:
    print(0)
    quit()
K = (X + Y) // 3
if X < K or Y < K:
    print(0)
    quit()
N1, N2 = K, X - K
print(nCk(N1, N2))
