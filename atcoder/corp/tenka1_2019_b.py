N = int(input())
A = [int(input()) for _ in range(N)]

sum_A = sum(A)
MOD = 998244353

dp1 = [0] * (sum_A + 1)
dp2 = [0] * (sum_A + 1)
dp1[0] = dp2[0] = 1
tmp_sum = 0

for a in A:
    for i in reversed(range(tmp_sum + 1)):
        dp1[i] %= MOD
        dp2[i] %= MOD
        dp1[i + a] += dp1[i]
        dp1[i] <<= 1
        dp2[i + a] += dp2[i]
    tmp_sum += a


ans = pow(3, N, MOD)
for i in range(sum_A + 1):
    if i * 2 >= sum_A:
        ans = (ans - dp1[i] * 3 + MOD * 3) % MOD
    if i * 2 == sum_A:
        ans = (ans + dp2[i] * 3) % MOD
print(ans)
