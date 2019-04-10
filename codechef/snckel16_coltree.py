T = int(input())
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


def nPk(n, k):
    assert 1 <= k <= n
    ret = 1
    for i in range(k):
        ret *= n - i
        ret %= mod
    return ret


for _ in range(T):
    N, K = map(int, input().split())
    for _ in range(N-1):
        input()
    ans = 0
    for i in range(1, min(N+1, K+1)):
        ans += nCk(N-1, i-1) * nPk(K, i) % mod
        ans %= mod
    print(ans)
