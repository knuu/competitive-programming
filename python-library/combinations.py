mod = 10**9+7
def inv(x):
    return pow(x, mod-2, mod)
def nCk(n, k):
    ret = 1
    for i in range(k):
        ret *= n-i
        ret %= mod
        ret *= inv(i+1)
        ret %= mod
    return ret
def nHk(n, k):
    return nCk(n+k-1, k-1)
