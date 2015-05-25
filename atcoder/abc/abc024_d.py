mod = 10**9+7
def inv(x):
    return pow(x, mod-2, mod)
def nCk(n, k):
    assert 0 <= k <= n
    ret = 1
    for i in range(k):
        ret *= n-i
        ret %= mod
        ret *= inv(i+1)
        ret %= mod
    return ret
def nHk(n, k):
    assert 1 <= k <= n 
    return nCk(n+k-1, k-1)

A = int(input())
B = int(input())
C = int(input())

r = (B*C - A*C) % mod
c = (B*C - A*B) % mod
denom = inv(A*B - B*C + A*C)
print(r*denom%mod, c*denom%mod)
