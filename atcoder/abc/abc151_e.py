mod = 10**9+7


def inv(x):
    return pow(x, mod - 2, mod)


def nCr(n, k):
    return fact[n] * inv_fact[k] % mod * inv_fact[n-k] % mod

N, K = map(int, input().split())
if K == 1:
    print(0)
    quit()
A = [int(x) for x in input().split()]
A.sort()

fact = [1, 1]
inv_fact = [1, 1]
for i in range(2, N + 1):
    fact.append(fact[-1] * i % mod)
    inv_fact.append(inv(fact[-1]))


comb_sum = [0]
for i in range(N):
    if K - 2 + i > N:
        break
    comb_sum.append((comb_sum[-1] + nCr(K-2+i, K-2)) % mod)
ans = 0
for i in range(N):
    cnt = N - K + 1 - i
    if cnt > 0:
        ans = (ans + (mod - comb_sum[cnt]) * A[i]) % mod
    cnt = i + 2 - K
    if cnt > 0:
        ans = (ans + comb_sum[cnt] * A[i]) % mod
print(ans)
