mod = 10**9+7


def inv(x):
    return pow(x, mod - 2, mod)


N = int(input())
A = [int(x) for x in input().split()]
fact = [1, 1]

for i in range(2, N + 1):
    fact.append(fact[-1] * i % mod)
inv_sum = [0]
for i in range(1, N + 1):
    inv_sum.append((inv_sum[-1] + fact[N] * inv(i) % mod) % mod)

ans = 0
for i in range(N):
    ans += (inv_sum[i + 1] + inv_sum[N - i] - fact[N] + mod) % mod * A[i] % mod
    ans %= mod
print(ans)
