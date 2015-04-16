n = int(input())
k = int(input())

mod = 10**9 + 7
def inv(x):
    return pow(x, mod-2, mod)

ans = 1
n = n + k - 1
for i in range(k):
    ans *= n - i
    ans %= mod
    ans *= inv(i+1)
    ans %= mod
print(ans)
