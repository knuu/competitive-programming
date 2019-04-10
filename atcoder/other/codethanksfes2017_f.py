N, K = map(int, input().split())
A = [int(input()) for _ in range(N)]
A.sort()
dp = [[0] * int(2e5) for _ in range(2)]
dp[0][0] = 1
limit = 0
MOD = 10 ** 9 + 7
for i in range(N):
    prev, now = i % 2, (i + 1) % 2
    for j in range(limit + 1):
        dp[now][j] = dp[prev][j]
    for j in range(limit + 1):
        dp[now][j ^ A[i]] += dp[prev][j]
        dp[now][j ^ A[i]] %= MOD
    limit |= A[i]
print(dp[N % 2][K])
