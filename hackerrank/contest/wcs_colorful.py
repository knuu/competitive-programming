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


A, B, C, D = map(int, input().split())
memo = dict()
if B == 0 and D == 0:
    if A != 0 and C != 0:
        print(0)
    elif A == C == 0:
        print(2)
    else:
        print(1)
elif B == D:
    ans = 0
    ans += nCk(A + B, B) * nCk(C + B - 1, B - 1) % mod
    ans += nCk(A + B - 1, B - 1) * nCk(C + B, B) % mod
    print(ans % mod)
elif B == D + 1:
    print(nCk(A + D, D) * nCk(C + D, D) % mod)
elif B + 1 == D:
    print(nCk(A + B, B) * nCk(C + B, B) % mod)
else:
    print(0)
